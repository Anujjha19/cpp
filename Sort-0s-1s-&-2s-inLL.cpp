/*  // BASIC count approach
Node* sortList(Node *head)
{
    int zeroCount =0;
    int oneCount=0;
    int twoCount=0;
    
    Node * temp=head;
    while(temp != NULL ){
        if(temp-> data ==0){
            zeroCount++;
        }
        else if(temp-> data ==1){ 
            oneCount++;}
        else if(temp-> data ==2){ 
            twoCount++;}
        
        temp = temp -> next;
        
    }
    temp=head;
    while(temp != NULL){
        if(zeroCount != 0){ 
            temp->data =0;
        zeroCount--;}
        else if(oneCount != 0){ 
            temp->data =1;
        oneCount--;}
        else if(twoCount != 0){ 
            temp->data =2;
        twoCount--;
        }
        temp = temp-> next;
    }
    return head;

}
 */

// By creating Seperate Linked List and then Merging It

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}
Node* sortList(Node *head)
{
Node * zeroHead=new Node(-1);
Node * zeroTail=zeroHead;
Node * oneHead=new Node(-1);
Node * oneTail=oneHead;
Node * twoHead=new Node(-1);
Node * twoTail=twoHead;
    
    Node * curr = head;
    //Create seperate List of 0s, 1s, and 2s
    while(curr != NULL){
        int value= curr ->data;
        if(value ==0){
            insertAtTail(zeroTail , curr);
        }
        else if(value ==1){
            insertAtTail(oneTail , curr);
        }
        else if(value ==2){
            insertAtTail(twoTail , curr);
        }
        curr = curr -> next;
    }
    //Merge 3 sublist
    
    //1s list is not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    } else{ // 1s List is  empty
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead->next;
    twoTail -> next =  NULL;
    
    //Setup Head
    head = zeroHead -> next;
    
    //Delete Dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
return head;
}
