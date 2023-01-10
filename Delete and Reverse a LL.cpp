void deleteNode(struct Node **head, int key)
{

    Node* curr = *head;
    Node* prev = NULL;
    while(curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{

// Your code goes here

 Node* curr = *head_ref;
 Node* prev =NULL;
 Node* forward  =NULL;
while( curr -> next !=  NULL)
{
    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr= forward;
}
    curr -> next = prev;

    (*head_ref)=prev;
}