
//Detect  LOOP

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
} 
/*  // Main mai 

if(detectLoop(head)){
    cout <<"Loop is Present."<<endl;
}
else{
    cout<<"Loop is not Present." <<endl;
}
*/



// Detect Loop Using FLOYD's cycle detection algo


Node* floydDetectLoop(Node* head){
    if(head == NULL){
        return NULL ;
    }
    Node* slow=head;
    Node* fast=head;
    
    while(slow!=NULL && fast !=NULL){
        fast=fast->next;
        if(fast !=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

/* //Main Mai
if(floydDetectLoop(head)){
    cout <<"Loop is Present."<<endl;
}
else{
    cout<<"Loop is not Present." <<endl;
}*/


//Finding Starting NOde OF Loop
Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection =floydDetectLoop(head);
    Node* slow=head;
    while(slow != intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    
    return slow;
    
}
/*  // Main mai 

Node* loop = getStartingNode(head) ;
cout<< "Loops starts at Node : "  << loop->data <<endl; */

//Remove Loop

void removeLoop(Node* head){
    if(head==NULL){
        return ;
    }
    Node * startOfLoop = getStartingNode(head);
    Node* temp= startOfLoop;
    while( temp-> next != startOfLoop){
        temp= temp -> next;
    }
    temp -> next = NULL;
}

/*  // Main mai 

removeLoop(head);
print(head);

*/
