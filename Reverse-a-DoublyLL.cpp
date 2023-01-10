//RECURSIVE CODE FOR DOUBLY LINKED LIST



node* reverseLL(node* head){
    if(head==NULL || head->next==NULL)
        return head;
    
    node* chota=reverseLL(head->next);
    head->next->next=head;
    head->prev=head->next;
    head->next=NULL;
    return chota;
}




// reverse doubly linked list    code below 

void reverse(node*&head){
    node*current=head;
    node*prev=NULL;
    node*forward=NULL;

        while(current!=NULL){
            forward=current->next;
            current->pre=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
    head=prev;
+
}

/* 
doubly linked list reverse
Node* reverseDLL(Node * head)
{
   Node* curr=head;
   Node* pre=NULL;
   Node* forward=NULL;
   while(curr!=NULL){
       forward=curr->next;
       curr->prev=curr->next;
       curr->next=pre;
       pre=curr;
       curr=forward;
   }
   return pre;
} */
