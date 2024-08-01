#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insert_at_head(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insert_at_tail(node* &tail,int data){
    node* temp=new node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
void insert_at_position(node* &tail,node* &head,int position,int data){
    if(position==1){
        insert_at_head(head,data);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insert_at_tail(tail,data);
        return;
    }
    node* nodetobeinserted=new node(data);
    nodetobeinserted->next=temp->next;
    temp->next->prev=nodetobeinserted;
    temp->next=nodetobeinserted;
    nodetobeinserted->prev=temp;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    print(head);
    insert_at_head(head,5);
    print(head);
    insert_at_tail(tail,15);
    print(head);
    insert_at_position(tail,head,3,12);
    print(head);
}