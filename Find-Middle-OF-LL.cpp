
//All Answers are on LEETCODE


/* int getlength(Node *head){
    int len=0;
    while(head !=NULL){
        head=head->next;
        len++;
    }
return len;
}
Node *findMiddle(Node *head){
    int len=getlength(head);
    int ans =((len/2) );

    Node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp -> next;
        cnt++;
    }
    return temp;
} */

Node* getMiddle(Node* head){
    if(head == NULL || head-> next ==NULL){
        return head;
    }
    if(head-> next -> next == NULL){
        return head-> next;
    } 
    Node* slow =head;
    Node* fast =head->next;
    while(fast !=NULL){
        fast =fast ->next;
        if(fast !=NULL){
            fast= fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    // Write your code here
    return getMiddle(head);
}
