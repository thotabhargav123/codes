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
 void insert_at_head(node *&head,int val){
     node*n= new node(val);
    
     if(head==NULL){
         n->next = n;
         head=n;
         return;
     }
      node *temp = head;
     while(temp->next != NULL){
         temp = temp->next;
     }
     temp->next = n;
     n->next = head;
     head = n;
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
    //insert_at_head(head, 500);
    cout << "enter value of n" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        insert_at_tail(head,i+1);
    }
    insert_at_head(head, 100);
    display(head);
}
