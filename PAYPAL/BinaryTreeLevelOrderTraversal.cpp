// LEETCODE: 102. Binary Tree Level Order Traversal

// Pattern : Traversals

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>qu;
        if(!root) return ans;
        qu.push({root,root->val});
        while(!qu.empty())
        {  
             int size=qu.size();
             vector<int>temp;
             for(int i=0;i<size;i++)
             {  
                auto node=qu.front().first;
                temp.push_back(qu.front().second);
                qu.pop();
                if(node->left) qu.push({node->left,node->left->val});
                if(node->right) qu.push({node->right,node->right->val});
             }
             ans.push_back(temp);
        }
        return ans;
    }
};
//TIME COMPLEXITY: O(N)
//SPACE COMPLEXITY:O(N)

