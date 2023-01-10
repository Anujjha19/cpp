
Node* findIntersection(Node* head1, Node* head2)
{
   Node* ptr1= head1;
   Node* ptr2= head2;
   Node* head= NULL;
   Node* curr= NULL;
   
   while( ptr1 != NULL && ptr2 !=NULL)
   //while(ptr1 and ptr2)
   {
        if(ptr1 -> data == ptr2 -> data){
            if(head == NULL){
                Node* t= new Node( ptr1 -> data);
                head =t;
                curr =t;
            }
            else{
                Node* t= new Node( ptr1 -> data);
                curr -> next =t;
                curr = curr -> next;
            }
            ptr1= ptr1 -> next;
            ptr2 = ptr2 -> next;
        }  else{
            if(ptr1 -> data < ptr2 -> data){ 
             ptr1 = ptr1 -> next;
            }
            else{
                ptr2 = ptr2 -> next;
            }
        }
   }
   return head;
}
// Time Complexity = O( n + m);
// Space Complexity  = O (  n+ m) it is possible that all linked list can be common