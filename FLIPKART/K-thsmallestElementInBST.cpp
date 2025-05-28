// CODE 360:  Find K-th smallest Element in BST

// Pattern:BST Specific Problems

void inorder(BinaryTreeNode<int>* root,int k,int& small,int& count)
{
    if(!root) return;
    inorder(root->left,k,small,count);
    count++;

    if(count==k) 
    {
      small=root->data;
     // return  may or may not use return ,still both works
    }

    inorder(root->right,k,small,count);
   
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int small=-1;
    int count=0;
    inorder(root,k,small,count);
    return small;
}

// Time Complexity: O(n) (without return) , ( with return ) O(k)
// Space Complexity:O(h)
