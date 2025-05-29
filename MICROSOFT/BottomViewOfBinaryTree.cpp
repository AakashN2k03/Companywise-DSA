// CODE360:  Bottom View Of Binary Tree

// Pattern : View of Binary Tree

#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    vector<int>ans;
    if(!root) return ans;

    map<int,int>mpp; //  LINE, NODE VALUE
    queue<pair<TreeNode<int>*,int>>qu; // NODE , LINE
    qu.push({root,0});

    while(!qu.empty())
    {
        auto p=qu.front();
        qu.pop();
        int line=p.second;
        TreeNode<int>* temp=p.first;

        if(mpp.find(line)!=mpp.end()) mpp[line]=temp->data;
        else mpp[line]=temp->data;

        if(temp->left) qu.push({temp->left,line-1});
        if(temp->right) qu.push({temp->right,line+1});

    }
    for(auto& x:mpp)
    {
        ans.push_back(x.second);
    }
    return ans;
    
}
// Time Complexity:O(N log N)
// Space Complexity:O(N)
