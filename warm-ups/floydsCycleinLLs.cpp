bool detectCycle(node*head){
    node*slow = head;
    node*fast = head;

    while(fast!= NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast==slow){
            return true;
        }

    }
    return false;
}