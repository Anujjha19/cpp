vector <int> bottomView(Node *root) {
        
        vector<int>ans;
        if(root ==NULL) return ans;
        
        map<int , int > BottomNode;
        
        queue < pair < Node* , int > > q;
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            pair < Node* , int > temp = q.front() ;
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //If the line is present it changes the value to new value encounter
            BottomNode[hd] = frontNode -> data;
            
            if(frontNode -> left) {
                q.push(make_pair(frontNode -> left , hd-1));
            }
            if(frontNode -> right) {
                q.push(make_pair(frontNode -> right , hd
                +1)); 
            }
            
        }
        for(auto i: BottomNode){
            ans.push_back(i.second);
        }
        return ans;
        
    }

Time Complexity: O(N)
Space Complexity: O(N)

/* 
 vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            int x = q.front().first;
            Node* it = q.front().second;
            q.pop();
            mp[x] = it->data;
            if(it->left){
                q.push({x-1,it->left});
            }
            if(it->right){
                q.push({x+1,it->right});
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    } */