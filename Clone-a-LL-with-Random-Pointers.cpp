/* class Solution
{   
    private:
    void insertAtTail(Node* &head ,  Node* &tail , int d){
        Node* newNode= new Node(d);
        if(head == NULL){
            head= newNode;
            tail=newNode;
            return;
        }
        else{
            tail-> next = newNode;
            tail=newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Step1 Create a Clone List
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp= head;
        
        while(temp!= NULL){
            insertAtTail(cloneHead, cloneTail , temp->data);
            temp= temp->next;
        }
        //Step2 Create a Map
        unordered_map<Node* , Node* > oldToNewNode;
        Node* originalNode= head;
        Node* cloneNode=cloneHead;
        while( originalNode != NULL && cloneNode != NULL){
            oldToNewNode[originalNode]= cloneNode;
            originalNode= originalNode -> next;
            cloneNode= cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;
        
        while(originalNode != NULL){
            cloneNode-> arb = oldToNewNode[originalNode -> arb];
            originalNode = originalNode ->next;
            cloneNode= cloneNode -> next;
        }
            return cloneHead;
        
    }

}; */


//Without adding Extra Space
class Solution
{
    private:
    void insertAtTail(Node* &head , Node* &tail , int d){
        Node* newNode = new Node(d);
        if(head==NULL){
            head= newNode;
            tail=newNode;
        }else{
            tail->next = newNode;
            tail=newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Step1 create a clone List
        
        Node* cloneHead= NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead , cloneTail , temp ->data);
            temp=temp->next;
        }
        
        //Step2 cloneNode and in between Original 
        Node* originalNode =head;
        Node* cloneNode =cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode ->next = cloneNode;
            originalNode =next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode=next;
            
        }
        //Step3 random pointer copy
        
        temp = head;
        while(temp !=NULL){
            if(temp-> next != NULL){
                
                temp->next ->arb = temp -> arb ? temp ->arb 
                ->next :temp->arb;
                
                /*if(temp->random !=NULL){
                temp->next ->random = temp ->random ->next;
                }
                else{
                    // temp->next  =NULL;
                    temp->next = temp->random;
                }*/
            }
            temp= temp -> next -> next;
        }
        
        //Step4 revert changes done in step 2
        
        originalNode=head;
        cloneNode=cloneHead;
        
        while(originalNode != NULL && cloneHead != NULL){
            
            originalNode ->next = cloneNode ->next ;
            originalNode = originalNode -> next;
            
            if(originalNode !=NULL){
            cloneNode ->next = originalNode -> next;
            }
            cloneNode= cloneNode ->next;
        }
        
        
        //Step5 return ans
        
        return cloneHead;
    }

};