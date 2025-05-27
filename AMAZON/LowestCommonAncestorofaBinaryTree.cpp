// LEETCODE: 236.Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: If root is null or root is one of the nodes p or q, return root
        if (!root || root == p || root == q) return root;

        TreeNode* lh = lowestCommonAncestor(root->left, p, q);  // Search in left subtree
        TreeNode* rh = lowestCommonAncestor(root->right, p, q); // Search in right subtree

        // If left is null, LCA is in right subtree
        if (lh == nullptr) return rh;

        // If right is null, LCA is in left subtree
        if (rh == nullptr) return lh;

        // If both left and right are non-null, root is the LCA
        return root;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(h)
