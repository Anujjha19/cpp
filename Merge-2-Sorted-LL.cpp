#include <bits/stdc++.h> 

Node<int>* solve(Node<int>* first, Node<int>* second) {
    
    //If only one element is present in first
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
   Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> data >= curr1 -> data ) 
            && ( curr2 -> data <= next1 -> data)) {
            //Add node between first and second 
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //Update Pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            //Curr1 and next1 ko move ahead
            curr1= next1;
            next1= next1-> next;

            if(next1== NULL){
                curr1->next = curr2;
                return first;
            }
        }     
    }
    return first;
    
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data ){
        return solve(first, second);
    }
    else
    {
        return  solve(second, first);
    }
    
    
}
/* 
Recusive Approach

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if(!list1)return list2;
	if(!list2) return list1;
	ListNode* ans;
	if(list1->val<=list2->val){
		ans=new ListNode(list1->val);
		ans->next=mergeTwoLists(list1->next, list2);
	}
	else{
		ans= new ListNode(list2->val);
		ans->next= mergeTwoLists(list1, list2->next);
	}
	return ans;
}
 */