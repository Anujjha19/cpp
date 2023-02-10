void marksParent( TreeNode* root, TreeNode* target,
     map< TreeNode* , TreeNode*> &parentsTrack){
        queue<TreeNode*>q;
        q.push(root);
        //parentsTrack[root] =NULL;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                parentsTrack[curr->left] =curr;
                q.push( curr -> left);
            }
            if(curr->right){
                parentsTrack[curr->right] =curr;
                q.push(curr -> right);
            }
        }
     }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map< TreeNode* , TreeNode*> parentsTrack;
        marksParent(root,  target,parentsTrack );

        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] =true;
        int currLevel=0;

        while(!q.empty()){
            int size = q.size();

            if(currLevel++ == k) break;
            for( int i= 0; i< size ; i++){
                TreeNode* curr = q.front(); 
                q.pop();

                if( curr -> left && !visited[curr -> left] ){
                    visited[curr -> left] = true;
                    q.push(curr->left);
                }
                if( curr -> right && !visited[curr -> right] ){
                    visited[curr -> right] = true;
                    q.push(curr->right);
                }
                if( parentsTrack[curr] && !visited[parentsTrack[curr]] ){
                    visited[parentsTrack[curr]] = true;
                    q.push(parentsTrack[curr]);
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            result.push_back(curr -> val);
        }
        return result;
    }