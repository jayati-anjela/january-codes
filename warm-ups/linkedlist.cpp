#include<iostream>
#include<cstring>
using namespace std;

class node{

    public:
        int data;
        node*next;

        node(int d){
            data = d;
            next = NULL;
        }
};

void build(){

}

void insertAtHead(node*&head, int d){ //passing by reference
    if(head == NULL){
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n -> next = head;
    head = n;
}

void print(node*head){  // passing by value

    while(head!=NULL){
        cout<<head-> data<<" ";
        head = head-> next;
    }
}

// insert at tail

void insertAtTail(node*&head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail-> next;
    }

    tail->next = new node(data);
    return;
}

// insertion in the middle of the linked list
void insertInMiddle(node*&head, int data, int p){
    // edge case
    if(head==NULL or p==0){
        insertAtHead(head, data);
    }
    else if(p> string::length(head) ){
        insertAtTail(head,data); // creating it later
    }
    else{
        // take p-1 jumps
        int jump = 1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump++;
        }

        // create new node
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }

}



int main(){
    node*head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertInMiddle(head, 3, 2);
    insertInMiddle(head, 4, 3);
    insertAtTail(head,7);
    print(head);

}