// CODE360:  Topological Sort

// Pattern - Topological Sort ( Kahn’s Algorithm + BFS)

//NOTE: TOPOSORT ONLY APPLICABLE TO DAG

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>>adjls(v);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        adjls[u].push_back(v);
    }

    vector<int>indegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto it:adjls[i])
        {
            indegree[it]++;
        }
    }

    queue<int>qu;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0) qu.push(i);
    }

    vector<int>ans;
    while(!qu.empty())
    {
        int node=qu.front();
        qu.pop();

        ans.push_back(node);
        for(auto it:adjls[node])
        {
            indegree[it]--;
            if(indegree[it]==0) qu.push(it);
        }
    }
    return ans;

}
// Time Complexity:O(V+E)
// Space Complexity:O(V+E)

// Note:Kahn's Algorithm is one method to solve Topological Sort.
// It uses BFS + Indegree (inward edges) approach.
