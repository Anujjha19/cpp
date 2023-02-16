class BSTIterator {
    private : stack<TreeNode*> ans;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = ans.top();
        ans.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
    private:
    void pushAll( TreeNode* node ){
        for( ; node!=NULL ; ans.push(node) , node = node->left);
    }
};
