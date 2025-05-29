// CODE360: Right View Of a Binary Tree

// Pattern : View of Binary Tree

void right_view(BinaryTreeNode<int>*root,int level,vector<int>& ans)
{
    if(!root) return ;
    if(ans.size()==level) ans.push_back(root->data);
    right_view(root->right,level+1,ans);
    right_view(root->left,level+1,ans);

}
vector<int> printRightView(BinaryTreeNode<int>* root) {
   vector<int>ans;
   int level=0;
   right_view(root,level,ans);
   return ans;
}
// Time Complexity:  O(n)
// Space Complexity: O(h)
