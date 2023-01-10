
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_set<int>seen;
        Node* curr = head;
        
        if(curr == NULL)
            return head;
        else
            seen.insert(curr->data);
            
        while(curr != NULL && curr->next != NULL){
            if(seen.find(curr->next->data) != seen.end()){
                // same 
                curr->next = curr->next->next;
            }else{
                // not same
                seen.insert(curr->next->data);
                curr = curr->next;
            }
        }
        return head;
    }
};




/* 
#include <unordered_map>
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    // Keep track of previous node.
    Node *prev = NULL;
    unordered_map<int, bool> seen;
    // Iterate over the given linked list.
    while (curr != NULL)
    {
        int val = curr->data;
        if (seen[val])
        {
            // Node has been encountered before, so its a duplicate.
            // Firstly update the next pointer of the previous node.
            prev->next = curr->next;
            // Delete the duplicate node.
            delete curr;
            // Move on to the next node.
            curr = prev->next;
        }
        else
        {
            // Node is seen for the first time, so add it to hash table.
            seen[val] = true;
            // Move on to the next node.
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}  */









/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the Linked list.
*/




/* // TLE  --  because as we r taking two loop so  --- the T.C = O(n*n)
Node *removeDuplicates(Node *head)
{
    Node * curr = head;
    while(curr != NULL){
        Node* temp = curr -> next;
        while(temp!= NULL){
            if(curr -> data == temp-> data ){
               Node * hi = temp -> next;
                delete(hi);
            }
        } 
    }
    return head;
}
 */