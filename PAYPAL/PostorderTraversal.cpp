// CODE360: Postorder Traversal 

void fn(TreeNode* root,vector<int>&ans)
{
    if(!root) return;
    fn(root->left,ans);
    fn(root->right,ans);
    ans.push_back(root->data);

}
vector<int> postorderTraversal(TreeNode *root)
{   
     vector<int>ans;
     fn(root,ans);
     return ans;
}
// Time Complexity: O(n)
// Space Complexity: O(h) + O(n)
// O(h) for the recursive call stack, where h is the height of the tree
// O(n) for the 'ans' vector storing all node values
