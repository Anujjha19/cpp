/*
    Time Complexity: O(N * K)
    Space Complexity: O(1),

    where N is the number of elements in the doubly linked list and K is the maximum deviation of an element from its target position.
*/

Node *sortedDll(Node *head, int k) {

    // Assign the head of the Linked List to current.
    Node *current = head;

    // Traverse till you you reach the end of the list.
    while (current != NULL) {
        Node *back = current->prev;
        int key = current->data;

        // Swapping if value of back->data is greater than key value.
        while (back != NULL && key < back->data) {
            back->next->data = back->data;
            back = back->prev;
        }

        // If back pointer points to NULL, update data of head as given.
        if (back == NULL) {
            head->data = key;
        }

        else {
            back->next->data = key;
        }

        // Updating the value of current as given.
        current = current->next;
    }

    return head;
}