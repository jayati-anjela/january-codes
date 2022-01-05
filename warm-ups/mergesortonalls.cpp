//  required code -> 
/* midpointpointer.cpp -> divide func i think
    this file -> recursively sort both sections
    remerge the two sections -> mergetwosortedllsintoone.cpp

*/

node* mergeSort)node*head{
    // base call
    if(head==NULL or head -> next == NULL){
        return head;
    }

    // rec case
    //1. Break case
    node* mid = midpoint(head);
    node*a = head;
    node*b = mid->next;

    mid->next = NULL;

    // 2. rec sort the two part
    a = mergeSort(a);
    b = mergeSort(b);

    // 3. merge them
    node* c = merge(a,b);
    return c;
}

// in linkedlist - O(n) Time - O(n log n)
// in array - O(1) Time - O(n log n)