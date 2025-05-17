// LEETCODE: Minimum Depth of Binary Tree

// Pattern : Depth / Height / Diameter Based

int minDepth(TreeNode* root) {
    if (!root) return 0; // Base case: null node → depth = 0

    int left_subtree = minDepth(root->left); 
    int right_subtree = minDepth(root->right); 

    if (!root->left || !root->right)
        return 1 + max(left_subtree, right_subtree);  // One child is missing

    return 1 + min(left_subtree, right_subtree);      // Both children exist
}
// Time Complexity: O(N)
// Space Complexity: O(H) STACK SPACE
