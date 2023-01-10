// Circular LINKED LIST

bool isCircular(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }
    // node of 1 and greater than 1 are overlapping logic wise

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        {
            temp = temp->next;
        }
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// T.C =O(n)
// S.C =O(1)

int main()
{
    // Write Self

    if (isCircularLL(tail))
    {
        cout << "Yes , LL is Circular " << endl;
    }
    else
    {
        cout << "No , LL is not Circular ." << endl;
    }

    return 0;
}
/*   //TLE
bool isCircular(Node *head)
{
   Node *temp = head;
   while(temp != NULL && temp->next != NULL) {
       temp = temp -> next;
       if(temp == head) {
           return true;
       }
   }
   return false;
}
 */

#include <unordered_map>
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return 0;
        map<ListNode *, bool> mp;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (!mp[temp])
            {
                mp[temp] = 1;
                temp = temp->next;
            }
            else if (mp[temp] == 1)
            {
                return 1;
            }
        }
        return 0;
    }
};

/* // using map approach (is circular or not)
T.C + S.C = O(n)

#include <unordered_map>
bool isCircular(Node *head)
{
   // Your code here
   if( head == NULL){
       return true;
   }
   unordered_map<Node* , bool > m;
   m[head] = true;
   Node* temp = head -> next;
   while(temp != NULL && temp != head){
       m[temp] = true;
       temp = temp -> next;
   }
   if(m[temp]){
       return true;
   }
   else{
       return false;
   }

}

 */