class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *addOne(Node *head)
    {
        Node *newHead = reverse(head);
        Node *curr = newHead;
        Node *prev = NULL;
        Node *curr1 = newHead;

        int carry = 0;
        while (curr != NULL)
        {
            int sum = 0;
            if (prev == NULL)
            {
                sum = curr->data + 1;
            }
            else
            {
                sum = curr->data + carry;
            }
            carry = sum / 10;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
        }
        /* if(carry ==1){
            Node* newNode = new Node(1);
            prev -> next = newNode;
        } */
        if (carry)
        {
            Node *newNode = new Node(carry);
            prev->next = newNode;
        }
        return reverse(curr1);
    }
};