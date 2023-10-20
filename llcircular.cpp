#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int val){
            data = val;
            next =NULL;
        }
};
 void insert_at_head(node* &head, int val){
    node* n=new node(val);
 
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
 void insert_at_tail(node* &head,int val){
      if(head==NULL){
         insert_at_head(head,val);
         return;
     }
     node*n= new node(val);
     node*temp= head;
    
     while(temp->next!=head){
         temp= temp->next;
     }
     temp->next = n;
      n->next = head;
 }
 void insert_after_given_index(node* &head,int val,int index){
      node*n= new node(val);
      node*temp= head;
     if(index==0){
         insert_at_head(head,val);
         return;
     }
     if(head==NULL){
         insert_at_head(head,val);
         return;
     }
     for (int i = 1;i<index;i++) {
          if(temp->next==head){
              insert_at_tail(head, val);
              return;
          }
          temp= temp->next;
     }
     n->next = temp->next;
     temp->next = n;
 }
void delete_at_head(node* &head){
      node* temp = head;
      while(temp->next!=head){
          temp= temp->next;
      }
      node *dobey = head;
      temp->next = head->next;
      head=head->next;
      delete dobey;
}
  void deletion (node *& head,int pos){
         if(pos==1){
             delete_at_head(head);
         }
         node*temp= head;
         for(int i=1;i<pos-1;i++) {
              temp= temp->next;
         }
         node*dobey=temp->next;
         temp->next=temp->next->next;
         delete dobey;
  }
 void display(node * &head){
     node*temp= head;
     do{
         cout << temp->data << " ";
         temp= temp->next;
     } while (temp != head);
     cout << endl;
 }
int main(){
    node *head = NULL;
    insert_after_given_index(head, 100, 100);
    cout << "enter value of n" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        insert_at_tail(head,i+1);
    }
    insert_after_given_index(head, 200, 0);
    insert_after_given_index(head,300,100);
    insert_after_given_index(head, 400, 3);
    display(head);
    deletion(head,3);
    display(head);
    deletion(head, 1);
    display(head);
    deletion(head, 10);
    display(head);
}