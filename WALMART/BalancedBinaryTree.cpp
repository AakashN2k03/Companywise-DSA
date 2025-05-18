// LEETCODE: 110. Balanced Binary Tree

// Pattern : Depth / Height / Diameter Based

class Solution {
public:
    int check(TreeNode* root)
    {
        if(!root) return 0;
        int left_subtree=check(root->left);
        int right_subtree=check(root->right);

        if(left_subtree==-1) return -1; // for left skew tree
        if(right_subtree==-1) return -1;// for left skew tree

        if(abs(left_subtree-right_subtree)>1) return -1;

        return 1+max(left_subtree,right_subtree);


    }
    bool isBalanced(TreeNode* root) {
       return check(root)!=-1; 
    }
};
//Time Complexity: O(N)
//Space Complexity:O(H)
