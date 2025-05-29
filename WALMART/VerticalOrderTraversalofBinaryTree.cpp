// CODE360: Vertical Order Traversal of Binary Tree

// Pattern : View of Binary Tree

#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<vector<int>> ans;  // to hold vertical columns temporarily
    if(!root) return {};      // return empty vector<int>

    map<int, map<int, multiset<int>>> node; // VL, LEVEL, NODE VAL
    queue<pair<TreeNode<int>*, pair<int,int>>> qu; // NODE, VL, LEVEL
    qu.push({root, {0, 0}});

    while(!qu.empty())
    {
        auto p = qu.front();
        qu.pop();
        TreeNode<int>* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;

        node[x][y].insert(temp->data);

        if(temp->left)
            qu.push({temp->left, {x-1, y+1}});
        if(temp->right)
            qu.push({temp->right, {x+1, y+1}});
    }

    // Gather columns in order
    for(auto &p : node)
    {
        vector<int> col;
        for(auto &q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    // Flatten ans into a single vector<int>
    vector<int> res;
    for (auto &col : ans)
        res.insert(res.end(), col.begin(), col.end());

    return res;
}
// Time Complexity:O(N log N)
// Space Complexity:O(N)
