// CODE360:  Left View Of a Binary Tree

// Pattern 5: View of Binary Tree

void left_view(TreeNode<int>*root,int level,vector<int>& ans)
{
    if(!root) return ;
    if(ans.size()==level) ans.push_back(root->data);
    left_view(root->left,level+1,ans);
    left_view(root->right,level+1,ans);

}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    int level=0;
    left_view(root,level,ans);
    return ans;
}
// Time Complexity:  O(n)
// Space Complexity: O(h)
