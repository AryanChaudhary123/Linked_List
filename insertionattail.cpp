#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertattail(node* &tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=tail->next;
}
void print(node* &tail){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
node* node1=new node(10);
//cout<<node1->data<<endl;
node* head=node1;
node* tail=node1;
print(head);
insertattail(tail,12);
print(head);
insertattail(tail,15);
print(head);
}