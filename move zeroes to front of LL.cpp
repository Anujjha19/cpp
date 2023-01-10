Node* moveZeroes(  Node* head);
{
    if(head ==NULL){
        return;
    }
    Node* temp= head -> next;
    Node* prev= head ;

    while(temp != NULL){
        if(temp -> data == 0){
            Node* curr = temp;
            temp = temp -> next;
            prev-> next = temp;
            curr -> next = head;
            head = curr;
        }else{
            prev= temp;
            temp= temp -> next;
        }
    }
}
