mode* midpoint(node*head){
    if(head==NULL or head->==NULL){
        return head;
    }

    node*slow = head;
    node*fast = head->next;

    while( fast!= NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// calling code would be node* mid = midpoint(head);