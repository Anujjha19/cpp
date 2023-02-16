void findInorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    findInorder(root->left, in);
    in.push_back(root->val);
    findInorder(root->right, in);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> in;
    findInorder(root, in);

    int i = 0;
    int j = in.size() - 1;
    while (i < j)
    {
        int sum = in[i] + in[j];

        if (sum == k)
            return true;

        else if (sum > k)
            j--;
        else
            i++;
    }
    return false;
}

/*

class BSTIterator  {
stack<TreeNode* > myStack;
//Reverse = true before
//Reverse = false next
bool reverse = true  ;

public:
  BSTIterator( TreeNode* root , bool isRev ){
      reverse= isRev;
      pushAll(root);
  }

  bool hasNext(){
      return !myStack.empty();

  }

  int next(){
      TreeNode* temp = myStack.top();
      myStack.pop();

      if( !reverse ) pushAll(temp->right);
      else pushAll(temp->left);

      return temp->val;
  }

  private:
  void pushAll(TreeNode* node){
      for( ; node!= NULL ;){
          myStack.push(node);
          if( reverse == true )
          node = node -> right;

          else
          node= node->left;

      }

  }
};

class Solution {
public:
bool findTarget(TreeNode* root, int k) {

    if( root ==NULL) return false;
    BSTIterator l( root , false); //next
    BSTIterator r( root , true); //before

    int  i = l.next();
    int j = r.next();
    while( i< j){
        if( i+ j == k) return true ;
        else if( i+ j < k) i =  l.next();
        else j= r.next();
    }
    return false;
}
};

 */