#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*next;
        node*prev;
        node(int val){
            data=val;
            next = NULL;
            prev = NULL;
        }
};
void insert_begin(node*&head,int val){
       node*n=new node(val);
      if(head!=NULL){
       head->prev=n;
       }
       n->next=head;
       
       head = n;
}
void insert_end(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node*temp=head;
  while(temp->next!=NULL){
      temp=temp->next;
  }
  temp->next = n;
  n->prev = temp;
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout<<"\n";
    return;
}
void printreverse(node*&head){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->prev;
    }
    cout<<"\n";
}
void insert_after_given_index(node*&head,int index,int val){
    node *n = new node (val);
    node *temp = head;
    if(head==NULL){
        insert_begin(head,val);
        return;
    }
    if(index==0){
         insert_begin(head,val);
         return;
    }
    for (int i = 1;i<index;i++){
        if(temp->next==NULL){
            insert_end(head,val);
            return;
        }
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev=temp;
}
void delete_node(node*&head,int pos){
         node* temp=head;
         if(pos==1){
             node *dobe = head;
             head = head->next;
             delete dobe;
             head->prev = NULL;
             return;
         }
         for (int i = 1;i<pos;i++){
             temp=temp->next;
         }
         
         node *dobey = temp;
         temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev =temp->prev;
          }
         delete dobey;
}
void delete_value(node*&head,int val){
    node*temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    if(temp->prev==NULL){
             node *dobe = head;
             head = head->next;
             head->prev = NULL;
             delete dobe;
             return;
    }
    node*dobey=temp;
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
    temp->next->prev =temp->prev;
    }
    delete dobey;
    return;
}
int length(node*head){
    node*temp=head;
    int l = 0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
node*appendk(node*&head,int k){
    cout<<length(head)<<endl;
    int len;
    len = length(head);
    k = k % len;
    int count = 1;
    node *newhead;
    node *newtail;
    node *tail=head;
    while(tail->next!=NULL){
        if(count==len-k){
            newtail = tail;
        }
        if(count==(len-k)+1){
            newhead = tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next =head;
    cout<<"new tails is "<<newtail->data<<endl;
    cout<<"new head is "<<newhead->data<<endl;
    cout<<"head is "<<tail->next->data<<endl;
    cout<<"tail is "<<tail->data<<endl;
    return newhead;
}
void check_intersection(node* &head1,node* &head2){
    int d = 0;
    int l1=length(head1);
    int l2=length(head2);
    node *ptr1;
    node *ptr2;
    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d=l2 -l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d){
        if(ptr1==NULL){
            cout<<"-1"<<endl;
            return;
        }
         ptr1=ptr1->next;
         d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            cout<<"Intersection found at "<<ptr1->data<<endl;
            return;
        }
        ptr1=ptr1->next;
        ptr2 = ptr2->next;
    }
    cout<<"No intersection found "<<endl;

}
void make_intersection(node*&head1,node*&head2,int pos){
    
     node*temp=head1;
     node *ptr1;
     node*temp2=head2;
     while(pos!=1){
         temp = temp->next;
         pos--;
     }
     while(temp2->next !=NULL){
         temp2 = temp2->next;
     }
     temp2->next =temp;
}
void check(node *&head){
    node*last=head;
    node*front=head;
    while(last->next != NULL){
        last=last->next;
    }
    cout << "last data is " << last->data << endl;
    while(front->next != NULL){
          if(front->data!=last->data){
              cout << "not a palindrome " <<last->data<< endl;
              return;
          }
          front=front->next;
          last = last->prev;
    }
    cout<<"palindrome "<< endl;
}
int main(){
    node *head1 = NULL;
    for (int i = 0;i<6;i++){
        insert_end(head1,i+1);
    }
    print(head1);
    node *head2 = NULL;
    for (int i = 1; i <=3;i++){
        insert_end(head2, (i * 10));
    }
    print(head2);
    check_intersection(head1, head2);
    make_intersection(head1, head2, 5);
    check_intersection(head1, head2);
}