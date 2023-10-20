#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};
void insert_begin(node * &head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insert_end(node * &head, int val ){
    node *n = new node(val);
    if(head == NULL){
        cout << " HGG "<<endl;
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
       temp = temp->next;
    }
    temp->next = n;
}
void insert_after_index(node * &head,int pos, int val){
        node *n = new node(val);
        if (head == NULL) {
         cout << "NO VALUE IN HEAD SO HEAD POINTER IS FILLED FIRST " << endl;
         head = n;
         return;
        }
        if(pos ==0){
            cout<<"INSERTION AT BEGINNING TAKES PLACE "<<endl;
            n->next = head;
            head = n;  
            return;
        }
         node *temp = head;
        for (int i = 1;i<pos;i++){
            if(temp->next== NULL){
                 cout<<"out side of linked list .so insertion at end takes place "<<endl;
                 temp->next = n;
                 return;
             }
             temp= temp->next;
             
        }
        n->next = temp->next;
        temp->next = n;
}
   void display(node*head){
     node *temp=head;
     while(temp != NULL){
         cout << temp->data << " ";
         temp = temp->next;
     }
     cout<<"\n";
}
  void traverse(node*head,int loc){
         node *temp=head;
         for (int i = 1; i<loc; i++){
             temp=temp->next;
         }
         cout<<temp->data<<endl;
  }
  void sumof(node* &head){
      int sum = 0;
      node *temp= head;
      while (temp != NULL)
      {
          sum = sum + temp->data;
          temp = temp->next;
       }
       cout<<"THE SUM OF NUMBERS IS "<<sum<<endl;
  }
  void deletion_of_number(node * &head, int val){
        node*temp= head;
        if(head->data==val){
            node *temp1= head;
            head=head->next;
            delete temp1;
            return;
        }
      while(temp->next->data!=val){
          temp= temp->next;
      }
      node *dobey = temp->next;
      temp->next = temp->next->next;
      delete dobey;
      return;
  }
  void deletion_by_index(node * &head,int index){
      node *temp= head;
         if(index==1){
             node*temp1= head;
             head=head->next;
             delete temp1;
             return;
         }
         for (int i = 1;i<index-1;i++){
              temp=temp->next;
         }
         node*dobey= temp->next;
         temp->next = temp->next->next;
         delete dobey;
         return;
  }
  void reverse(node* &head){
      node *first = NULL;
      node*cur= head;
      node *adv;
     while(cur!= NULL){
         adv=cur->next;
         cur->next=first;
         first = cur;
         cur=adv;
     }
     display(first);
  }
 void reverse_k_nodes(node * &head,int k){
      node *first = NULL;
      node *curr = head;
      node *advance;
      for(int i=0;i<k;i++){
           advance =curr->next;
           curr->next=first;
           first = curr;
           curr = advance;
      }
      node*temp= first;
      while(temp != NULL){
          cout << temp->data << " ";
          temp = temp->next;
      }
      node*temp1=curr;
      while(temp1 != NULL){
        cout <<temp1->data <<" ";
        temp1 = temp1->next;
      }
  }
  void make_loop(node*&head,int pos){
      node* temp= head;
      int count = 1;
      node *circle;
      while(temp->next != NULL){
           if(count==pos){
               circle = temp;
           }
           temp = temp->next;
           count++;
      }
      temp->next =circle;
      cout<<"loop done "<<endl;
  }
  void check_loop(node*&head){
      node*slow= head;
      node*fast= head;
      while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                cout << "1" << endl;
                return;
            }
      }
      cout<<"0"<<endl;
      return;
  }
  void break_loop(node * &head){
       node*slow= head;
      node*fast= head;
       do{
           slow= slow->next;
           fast= fast->next->next;

       }while(slow!=fast);
       fast = head;
       while(fast->next!=slow->next){
           slow=slow->next;
           fast = fast->next;
           //slow=slow->next;
       }
       slow->next = NULL;
  }
void replace(node*&head, int pos,int val){
      node*n= new node(val);
      node*temp= head;
      for (int i = 1;i<pos-1;i++){
          temp=temp->next;
      }
      node*tesey = temp->next;
      temp->next = n;
      n->next = tesey->next;
}
void extras(node*&head){
    node*temp = head;
    node *temp1;
    node *dobey;
    while(temp!=NULL && temp->next!=NULL){
        //cout<<"now temp is "<<temp->data <<endl;
        temp1 = temp;
          while(temp1->next!=NULL){
              //cout<<"now temp1 is "<<temp1->data<<endl;
              if(temp1->next->data==temp->data){
                  //delete temp1
                 // cout << "poinde";
                  //cout<<temp1->next->data<<" "<<temp->data<<endl;
                  dobey = temp1->next;
                  temp1->next = temp1->next->next;
                  delete dobey;
              }
              else{
              temp1 = temp1->next;
              }
          }
           temp= temp->next;
    }
}
 void extra(node*&head){
     node*temp = head;
     node *clear;
     if(head==NULL){
         return;
     }
     while(temp->next!=NULL){
         if(temp->data==temp->next->data){
             clear = temp->next;
             temp->next =temp->next->next;
             delete clear;
         }
         else{
             temp=temp->next;
         }
     }
 }
 void merge_2_sorted_list(node*&head1, node*&head2){
     node *ptr1 = head1;
     node *ptr2 = head2;
     node *dummynode = new node(-1);
     node *p3=dummynode;
     while(ptr1!= NULL&& ptr2!=NULL){
         if(ptr1->data>=ptr2->data){
             p3->next = ptr2;
             ptr2=ptr2->next;
             p3=p3->next;
         }
         else{
             p3->next =ptr1;
             ptr1=ptr1->next;
             p3=p3->next;
         }
     }
     while(ptr1 != NULL){
         p3->next = ptr1;
         ptr1=ptr1->next;
         p3=p3->next;
     }
     while(ptr2 != NULL){
         p3->next = ptr2;
         ptr2=ptr2->next;
         p3=p3->next;
     }
     display(dummynode->next);
 }
 void odd(node *&head){
    node* odd=head;
    node* even=head->next;
    node* evenstart = even;
    while(odd->next != NULL&& even->next != NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next =odd->next;
        even=even->next;
    }
    odd->next = evenstart;
    if(odd->next==NULL){
        even->next = NULL;
    }
 }
int main(){
     node*  head = NULL;
    //  char choice;
    //  char opt;
    //  cout<<"                 **** INSERTION AT DIFFERENT POSITIONS *****                                                 "<<endl;
    //  cout<<"          "<<endl;
    //  cout <<"           OSE A"<<endl;
    //  cout <<"               TO INSERT AT THE END BY DEFAULT CHOOSE B"<<endl;
    //  cout<< "               TO INSERT AT THE ANY POSITIONS CHOOSE C     TO INSERT AT THE BEGINNING  BY DEFAULT CHO"<<endl;
    //  cout<< "               TO DISPLAY CHOOSE OPTION D "<<endl;
    //  cout<< "               TO FIND ELEMEENT AT CERTAIN POSITION ENTER P "<<endl;
    //  cout<<"                TO SUM OF THE ELEMEENT IN LIST ENTER S       "<<endl;
    //  cout<<"                TO DELETE ELEMENT FROM LIST BY VALUE ENTER V  "<<endl;
    //  cout<<"                TO DELETE ELEMENT FROM LIST BY INDEX ENTER I  "<<endl;
    //  do{
    //      cout<<"CHOOSE OPTION "<<endl;
    //      cin >> choice;
    //      if(choice=='A'){
    //          cout<<"ENTER NUMBER "<<endl;
    //          int n;
    //          cin>>n;
    //          insert_begin(head,n);
    //      }
    //      else if(choice=='B'){
    //          cout<<"ENTER NUMBER "<<endl;
    //          int n1;
    //          cin>>n1;
    //          insert_end(head,n1);
    //      }
    //      else if(choice=='C'){
    //          cout << "ENTER NUMBER " << endl;
    //          cout<<"ENTER POSITIONS"<<endl;
    //          int n2, pos;
    //          cin>>n2>>pos;
    //          insert_after_index(head,pos,n2);
    //      }
    //      else if(choice=='D'){
    //          cout<<"DISPLAYING NUMBER..."<<endl;
    //          display(head);
    //      }
    //      else if(choice=='P'){
    //          cout<<"ENTER POSITION..."<<endl;
    //          int pos;
    //          cin>>pos;
    //          cout << "DISPLAYING NUMBER AT GIVEN POSITION " << endl;
    //          traverse(head,pos);
    //      }
    //      else if(choice='S'){
    //          sumof(head);
    //      }
    //      else if(choice='V'){
    //          cout<<"Enter the value to delete "<< endl;
    //          int del;
    //          cin>>del;
    //          deletion_of_number(head,del);
    //          cout<<"LIST AFTER DELETING IS :"<< endl;
    //          display(head);
    //      }
    //      else if(choice='I'){
    //          cout<<"Enter the index of the number "<<endl;
    //          int del;
    //          cin>>del;
    //          deletion_by_index(head, del);
    //          cout<<"LIST AFTER DELETING IS :"<< endl;
    //          display(head);
    //      }
    //      cout<<"TO CONTINUE ENTER Y "<<endl;
    //      cin>>opt;
    //  }while(opt=='Y');
    // for(int i=0;i<5;i++){
    
    //     insert_end(head, i);
    // }
    // display(head);
    // odd(head);
    // display(head);
     insert_end(head, 1);
     insert_end(head, 2);
     insert_end(head, 3);
     insert_end(head, 4);
     insert_end(head, 5);
     insert_end(head, 6);
     display(head);
     reverse(head);
     display(head);
}
