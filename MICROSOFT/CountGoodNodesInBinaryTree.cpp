// LEETCODE: Count Good Nodes in Binary Tree

// Pattern : Path Based (Sum/Max/Exists)

// NOTE:A node is called "good" if no node on the path from the root to that node has a value greater than it.
// 👉 So for each node, if its value is greater than or equal to all its ancestors' values, it’s a good node.

class Solution {
public:
    int dfs(TreeNode* root,int maxi)
    {
        if(!root) return 0;

        int count=0;
        if(root->val>=maxi) 
        { 
          count++;
          maxi=root->val;
        }
        // maxi=max(root->val,maxi);

        count+=dfs(root->left,maxi);
        count+=dfs(root->right,maxi);

        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        return dfs(root,maxi);
        
    }
};

// Time Complexity:O(N)
// Space Complexity:O(H)
