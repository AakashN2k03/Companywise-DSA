// CODE 360: Maximum Depth Of A Binary Tree

// Pattern : Depth / Height / Diameter Based

int findMaxDepth(TreeNode<int> *root) 
{
	if(!root) return 0; // or return NULL ,don't use nullptr
    int left_subtree=findMaxDepth(root->left);
    int right_subtree=findMaxDepth(root->right);

    return 1+max(left_subtree,right_subtree);

}
//Time complexity:O(N)
//Space complexity:O(H) stack space

// NOTE: 
// NULL is a macro defined as 0 (from C era).
// nullptr was introduced in C++11 — it has a type (std::nullptr_t), which makes it safer and preferred in modern C++.
// nullptr is not returning a pointer — it's just a special keyword that represents a pointer with value null.
