#include<bits/stdc++.h>
using namespace std;

vector<int> verticalOrder(Node *root)
    {
        //  HD , levelWiseNODE [ level , nodes( list of Nodes ) ]
        map<int, map <int ,vector<int> > > nodes ;
        //  node*  , hd-level [ HD , level ]
        queue<pair <Node* , pair<int , int > > > q;
        
        vector<int> ans;
        if(root ==NULL) return ans;
        
        q.push(make_pair(root , make_pair( 0,0))); //In first ine Both is Zero
        
        while(!q.empty()){
            pair <Node* , pair<int , int > > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int HD = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[HD][lvl].push_back(frontNode -> data);
            if(frontNode -> left ) {
                q.push( make_pair(frontNode->left , 
            make_pair(HD-1 , lvl +1)));
                
            }
            
            if(frontNode -> right ) {
                q.push( make_pair(frontNode->right , 
            make_pair(HD+1 , lvl +1)));
                
            }
        }
        
            for (auto i : nodes){
                for(auto j:i.second){
                    for(auto k : j.second){
                        ans.push_back(k);
                    }
                }
            }
        
        return ans;
    }

    //Expected Time Complexity: O(N)
    //Expected Auxiliary Space: O(N)