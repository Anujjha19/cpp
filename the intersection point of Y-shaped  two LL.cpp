/*  
    Time Complexity: O(m*n), where m and n are number of nodes in two linked list. 
    Space Complexity: O(1), Constant Space is used.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB){
            ListNode* temp = headA;
            while(temp){
                 // if both Nodes are same
                if(temp == headB){
                    return headB;
                }
                temp = temp -> next;
            }
            headB = headB -> next;
        }
        // intersection is not present between the lists
        return NULL;
    }
}; */

class Solution {
public:
    int getLen(ListNode* root){
        ListNode* temp= root;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int h1 = getLen(headA);
        int h2 = getLen(headB);
        ListNode* ptr1 = h1 > h2 ? headA : headB;
        ListNode* ptr2 = h1 <= h2 ? headA : headB;
        int x = abs(h1-h2);
        while(x--){
            ptr1 = ptr1->next;
        }
        
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
