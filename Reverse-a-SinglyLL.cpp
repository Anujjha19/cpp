#include<iostream>
using namespace std;



class Node
{
	public:
	int data;
	Node *next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}


int main()
{

Node* node1 = new Node(15 );
Node* head = node1; 
insertAtHead(head, 12);
insertAtHead(head, 10);
insertAtHead(head, 1);
cout << "Before Reverse : " <<endl;
print(head);
// reverseLinkedList(head);

    Node* prev=NULL;
    Node* curr=head;
    solveRecursively(head , curr , prev);
    
    return head;

cout << "After Reverse : " <<endl;
print(head);



return 0;
}

//ALL answers are on LEETCODE

void solveRecursively(Node* &head , Node* &curr , Node* &prev ){
    //Base Case
    if(curr == NULL){
        head=prev;
        return ;
}
Node* forward=curr ->next;
solveRecursively(head , forward , curr);
curr -> next=prev;

}

Node* reverseLinkedList(Node *head){

Node* prev=NULL;
    Node* curr=head;
    solveRecursively(head , curr , prev);
    reurn head;

    /* if(head==NULL || head -> next ==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
 */


/* 
class Solution {
    public:
     ListNode* reverse1(ListNode* head) {
         if(head ==NULL || head->next ==NULL){
             return head;
         }
         ListNode* chotaHead= reverse1(head -> next); 
         head -> next -> next =head;
         head -> next = NULL;
         return chotaHead;
     }

public:
    
    ListNode* reverseList(ListNode* head) {
        return reverse1(head);
    }
}; */

/* class Solution {
    public:
    void solveRecursively(ListNode* &head , ListNode* &curr , ListNode* &prev ){
    //Base Case
    if(curr == NULL){
        head=prev;
        return ;
}
ListNode* forward=curr ->next;
solveRecursively(head , forward , curr);
curr -> next=prev;

}
public:
    
    ListNode* reverseList(ListNode* head) {
ListNode* prev=NULL;
    ListNode* curr=head;
    solveRecursively(head , curr , prev);
    
    return head;        
    }
}; */
/* 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head -> next ==NULL){
        return head;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* forward=NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
    }
}; */