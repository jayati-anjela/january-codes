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

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    
    node*temp = head->next;
    delete head;
    head = temp;
}

// searching in linked list -> linear search

bool search(node*head, int key){

    node*temp = head;
    while(temp!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

//recursively
bool searchRec(node*head, int key){
   if(head==NULL){
        return false;
    } 

    // rec case check at head, remaining linked list
    if(head->data == key){
        return true;
    }
    else{
        return searchRec(head->next, key);
    }
}

// Taking an input from user
node* inputdata(){

    int d;
    cin>>d;

    node*head = NULL;

    while(d!=-1){ // if taking in from a file, the condition should be while(cin>>d)
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

// operator overloading in case of lls

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os; // return type ostream& is cascading method
}

istream& operator<<(istream &is, node*&head){
    head = inputdata();
    return is;
}

int main(){
    // node*head = inputdata();
    // node*head2 = inputdata();

    node*head3;
    node*head4;
    cin>>head3>>head4;
    // insertAtHead(head, 5);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    // insertAtTail(head,7);

    // print(head);

    cout<<head3<<head4;

}