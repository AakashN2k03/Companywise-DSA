LEETCODE: 235. Lowest Common Ancestor of a Binary Search Tree

// Pattern : BST

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        if(root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        // travel right
        else if(root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        // if LCA root itself
        return root;
        
    }
};
// Time Complexity: O(n)
// Space Complexity:O(h)
