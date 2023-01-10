

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    //Empty List 
    if(head == NULL){
return NULL;
    }
    Node* curr =head;
    //Non-Empty List 
    while(curr != NULL){
    if((curr -> next != NULL ) &&  curr-> data == curr -> next -> data){ // case of Equal
        Node* next_next= curr ->  next -> next ;
        Node * nodeToDelete = curr -> next;
        delete( nodeToDelete);
        curr -> next = next_next;
    }else{ 
        //Not Equal
        curr = curr -> next;
    } 
}
    return head;
}

/* Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* curr = head;
    Node* temp;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else curr = curr->next;
    }
        return head;
    
} */