/*
class Solution
{
private:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {
        Node *temp = new Node(val);
        // Empty List
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        // Non- Empty List
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;
        Node *anshead = NULL;
        Node *anstail = NULL;

        while (first != NULL && second != NULL)
        {

            int sum = carry + first->data + second->data;
            int digit = sum % 10;

            // Node* temp= new Node(digit);
            // Created node and add in ans LL
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            int sum = carry + first->data;
            int digit = sum % 10;

            // Created node and add in ans LL
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            first = first->next;
        }
        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum % 10;

            // Created node and add in ans LL
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            second = second->next;
        }
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;

            // Created node and add in ans LL
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
        }
        return anshead;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // Reverse input LL
        first = reverse(first);
        second = reverse(second);

        // Add 2 LL
        Node *ans = add(first, second);

        // Step 3 reverse ans LL
        ans = reverse(ans);

        return ans;
    }
}; */

class Solution
{
private:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {
        Node *temp = new Node(val);
        // Empty List
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        // Non- Empty List
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;
        Node *anshead = NULL;
        Node *anstail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {

            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }
            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;

            // Node* temp= new Node(digit);
            // Created node and add in ans LL
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        }
        return anshead;
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // Reverse input LL
        first = reverse(first);
        second = reverse(second);

        // Add 2 LL
        Node *ans = add(first, second);

        // Step 3 reverse ans LL
        ans = reverse(ans);

        return ans;
    }
};