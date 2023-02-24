#include<bits/stdc++.h>

class compare
{
public:
    bool operator()(Node<int>*a, Node<int>*b)
    {
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>* , vector<Node<int>*> , compare> minHeap;

    int k= listArray.size();
    if ( k== 0 ) return NULL;

    for( int i=0; i<k ; i++){
        if( listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head =NULL;
    Node<int>* tail = NULL;

    while( minHeap.size() > 0){

        Node<int>* top= minHeap.top();
        minHeap.pop();

        if( top-> next != NULL){
            minHeap.push( top -> next);
        }

        if( head ==NULL ) {
            head = top;
            tail= top;

        }
        else{
            tail -> next = top;
            tail= top;
        }
    }

    return head;

}
