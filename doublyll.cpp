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
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int getlength(node* &head){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    print(head);
    cout<<getlength(head)<<endl;
}