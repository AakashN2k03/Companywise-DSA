// CODE360:  Binary Tree Maximum Path Sum

// Pattern : Path Based (Sum/Max/Exists)

int fn(TreeNode<int>*root,int& maxi)
{
    if(!root) return 0;
    int left=max(0,fn(root->left,maxi)); // ignore negative values
    int right=max(0,fn(root->right,maxi));

    maxi=max(maxi,(root->val+left+right));

    return root->val+max(left,right); // since we need sum we add up the node value
                                      //incase its height we use 1=max(left,right)

}
int maxPathSum(TreeNode<int>* root)
{
	int maxi=INT_MIN;
    fn(root,maxi);
    return maxi;
}

// Time complexity:O(N)
// Space complexity:O(H)
