#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=this;
    }
};
void insert_at_head(node* &head,int data){
    node* temp=new node(data);
    node* current=head;
    if(head==NULL){
        temp->next=temp;
        head=temp;
        return;
    }
    while(current->next!=head){
        current=current->next;
    }
    current->next=temp;
    temp->next=head;
    head=temp;
}
void insert_at_tail(node* &head,int data){
    if(head==NULL){
        insert_at_head(head,data);
        return;
    }
    node* temp=new node(data);
    node* current=head;
    while(current->next!=head){
        current=current->next;
    }
    current->next=temp;
    temp->next=head;
}
void print(node* &head){
    node* temp=head;
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
int main(){
    node* head=NULL;
    print(head);
    insert_at_tail(head,10);
    print(head);
    insert_at_tail(head,15);
    print(head);
    insert_at_head(head,5);
    print(head);
}