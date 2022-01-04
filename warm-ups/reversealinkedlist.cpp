void reverse(node*&head){
    node* C = head;
    node* P = NULL;
    node*N;

    while(C!=NULL){
        //save the next node
        N = C-> next;
        // make the current node point to prev
        C-> next = P;

        //update P and C, take them 1 step forward
        P = C;
        C = N;
    }
    head = P;
}

// recursively reverse a linkedlist

node* recReverse(node*head){
    //smallest linked list
    if(head->next==NULL or head==NULL){
        return head;
    }

    //rec case
    node* shead = recReverse(head->next);

    node*temp = head-> next; 
    temp->next = head;
    head->next = NULL;
    return shead;
}