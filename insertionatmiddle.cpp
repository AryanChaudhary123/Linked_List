#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertionathead(node* &head, node* &tail, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
    // Update tail if the list was previously empty
    if (tail == NULL) {
        tail = head;
    }
}

void insertattail(node* &tail, int data) {
    node* temp = new node(data);
    if (tail != NULL) {
        tail->next = temp;
        tail = tail->next;
    }
}

void insertatmiddle(node* &tail, node* &head, int position, int data) {
    if (position == 1) {
        insertionathead(head, tail, data);
        return;
    }

    node* temp = head;
    int count = 1;
    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If inserting at the end, update the tail
    if (temp->next == NULL) {
        insertattail(tail, data);
        return;
    }

    node* nodetobeinserted = new node(data);
    nodetobeinserted->next = temp->next;
    temp->next = nodetobeinserted;
}
void print(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);

    insertionathead(head, tail, 5);
    print(head);

    insertattail(tail, 12);
    print(head);

    insertattail(tail, 15);
    print(head);

    insertatmiddle(tail, head, 3, 11);
    print(head);

    insertatmiddle(tail, head, 1, 3);
    print(head);

    insertatmiddle(tail, head, 7, 18);
    print(head);

    return 0;
}
