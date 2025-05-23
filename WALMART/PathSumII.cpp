// LEETCODE: 113. Path Sum II

// Pattern : Path Based (Sum/Max/Exists)

class Solution {
public:
    void dfs(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(!root) return;
        temp.push_back(root->val);
        targetSum-=root->val;

        if(!root->left && !root->right && targetSum==0)
        {
            ans.push_back(temp); // Found a valid path
        }

        dfs(root->left,targetSum,ans,temp);
        dfs(root->right,targetSum,ans,temp);

        temp.pop_back(); // backtrack
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(root,targetSum,ans,temp);
        return ans;
        
    }
};

// Time Complexity:O(N)
// Space Complexity:O(H) // STACK SPACE
