// CODE360: Top View Of Binary Tree

// Pattern : View of Binary Tree

#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{   if(!root) return {};

    map<int,int>mpp;                 // LINE, NODE VALUE
    queue<pair<TreeNode<int>*,int>>qu;    // Node , Line
    qu.push({root,0});
    while(!qu.empty())
    {
        auto p=qu.front();
        qu.pop();
        TreeNode<int>* temp=p.first;
        int line=p.second;

        if(mpp.find(line)==mpp.end()) mpp[line]=temp->data;

        if(temp->left) qu.push({temp->left,line-1});
        if(temp->right) qu.push({temp->right,line+1});

    }
    vector<int>ans;
    for(auto&x:mpp)
    {
        ans.push_back(x.second);
    }
    return ans;
}
// Time Complexity:O(N log N)
// Space Complexity: O(N)

//NOTE
// | Container       | Time Complexity (avg) | Time Complexity (worst) | Underlying DS  |
// | --------------- | --------------------- | ----------------------- | -------------- |
// | `std::map`      | O(log n)              | O(log n)                | Red-Black Tree |
// | `std::set`      | O(log n)              | O(log n)                | Red-Black Tree |
// | `unordered_map` | O(1)                  | O(n)                    | Hash Table     |
// | `unordered_set` | O(1)                  | O(n)                    | Hash Table     |
