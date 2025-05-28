// CODE 360:  Validate BST

// PATTERN: BST Specific Problems

bool validate(BinaryTreeNode<int>* root,int mini,int maxi) 
{
      if(!root) return true;

      if(root->data <= mini || root->data >= maxi) return false;
    
      return validate(root->left,mini,root->data) && validate(root->right,root->data,maxi);
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return validate(root,INT_MIN,INT_MAX);
}

// Time Complexity:O(n) 
// Space Complexity:O(h) 
