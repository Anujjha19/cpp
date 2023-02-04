#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data ;
    struct Node* left;
    struct Node* right;

    Node (int d){
        data =d;
         right = NULL;
        left = NULL;

    }
};

void printPostOrder( Node* root ){
    if( root==NULL) return ;

    printPostOrder( root ->left );
    printPostOrder( root -> right);
    cout << root -> data << " " ;

}


class Solution {

public:

    int findPosition( int in[] , int element , int n){
        for( int i=0  ; i< n; i++){
            if( in[i] == element)
            return i;
        }
        return -1;

    }

    Node *solve ( int in[] , int pre[] , int preIndex , int inStart , int inEnd , int n){
        // Base Case 
        if( preIndex >= n || inStart > inEnd){
            return NULL;
        }

        //Push the first Pre Element as Root 
        int element = pre[ preIndex++];
        Node *root = new Node(element);

        //Find The Root in InOrder
        int position= findPosition( in , element , n );

        //Recursively Call for Right , Left

        root -> left = solve ( in, pre , preIndex , inStart , position-1 , n);
        root -> right = solve ( in, pre , preIndex , position+1 ,inEnd,  n);

        return root ;

    }


Node* buildTree( int in[] , int pre[] , int n){

    int preIndex =0;
    Node * ans =  solve ( in, pre , preIndex , 0 , n-1 , n);

    return ans;
}


};


int main(){

    int t ;
    cin >> t;

    while( t--){

        int n;
        cin >> n;

        int inOrder[n];
        int preOrder[n];

        for( int i= 0 ; i< n ; i++){
            cin>> inOrder[i];
        }
        for( int i= 0 ; i< n ; i++){
            cin >> preOrder[i];
        }
        
        Solution obj;

        Node* root = obj.buildTree( inOrder , preOrder , n);
        
        printPostOrder(root);
        cout << endl;


    }
}