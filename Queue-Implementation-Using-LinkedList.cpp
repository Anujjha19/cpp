/* #include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;

    }
};

class queue{
    node* front;
    node* back;
    public:

    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n= new node(x);
        if(front ==NULL){
            back=n;
            front=n;
            return;
        }
        back-> next =n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue UnderFlow" <<endl;

        }else{
            node *toDelete= front;
            front= front->next;
            delete toDelete;
        }
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in Queue " <<endl;
            return -1;

        }else{
            front ->data;

        }
    }

    bool isEmpty(){
        if(front==NULL){
            return true;

        }
        else{
            return false;
        }
    }

    
};

int main()
{

queue q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);

cout<< q.peek() <<endl;
q.pop();
cout<< q.peek() <<endl;

    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

struct Queue {
	QNode *front, *rear;
	Queue() { front = rear = NULL; }

	void enQueue(int x)
	{

		// Create a new LL node
		QNode* temp = new QNode(x);

		// If queue is empty, then
		// new node is front and rear both
		if (rear == NULL) {
			front = rear = temp;
			return;
		}

		// Add the new node at
		// the end of queue and change rear
		rear->next = temp;
		rear = temp;
	}

	// Function to remove
	// a key from given queue q
	void deQueue()
	{
		// If queue is empty, return NULL.
		if (front == NULL)
			return;

		// Store previous front and
		// move front one node ahead
		QNode* temp = front;
		front = front->next;

		// If front becomes NULL, then
		// change rear also as NULL
		if (front == NULL)
			rear = NULL;

		delete (temp);
	}
};


int main()
{

	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->data << endl;
	cout << "Queue Rear : " << (q.rear)->data;
}
