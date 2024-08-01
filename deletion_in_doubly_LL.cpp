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
void del_at_beg(node* &head){
    node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
}
void del_at_tail(node* &head){
    node* currentnode=head;
    node* prevnode;
    while(currentnode->next!=NULL){
        prevnode=currentnode;
        currentnode=currentnode->next;
    }
    if(currentnode==head){
        head=NULL;
        delete(currentnode);
    }
    prevnode->next=NULL;
    delete(currentnode);
}
void del_at_position(node* &head,node* &tail,int position){
    if(position==1){
        del_at_beg(head);
        return;
    }
    int i=1;
    node* temp=head;
    node* nextnode;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        del_at_tail(head);
        return;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    nextnode->next->prev=temp;
    delete(nextnode);
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
    insert_at_tail(tail,18);
    print(head);
    insert_at_head(head,2);
    print(head);
    del_at_beg(head);
    print(head);
    del_at_tail(head);
    print(head);
    del_at_position(head,tail,3);
    print(head);
}