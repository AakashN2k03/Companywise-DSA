// LEETCODE: 112. Path Sum

// Pattern : Path Based (Sum/Max/Exists)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        if(!root->left && !root->right) // check leaf nodes
        {
            return targetSum==root->val;
        }
        // Recur for left and right subtree with updated sum
        return hasPathSum(root->left,targetSum-root->val) ||
         hasPathSum(root->right,targetSum-root->val);
        
    }
};

// Time Complexity:O(N)
// Space Complexity:O(H) recursion stack where H = height of tree.
