// CODE360:  Detect Cycle In A Directed Graph

// Pattern  - Topological Sort ( Kahn’s Algorithm + BFS)

#include<bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>>adjls(n+1);
    for(auto edge:edges)
    {
      int u=edge.first;
      int v=edge.second;

      adjls[u].push_back(v);
    }

    vector<int>indegree(n+1,0);
    for(int i=1;i<=n;i++)
    {
      for(auto it:adjls[i])
      {
        indegree[it]++;
      }
    }

    queue<int>qu;
    for(int i=1;i<=n;i++)
    {
      if(indegree[i]==0)
      {
        qu.push(i);
      }
    }
    int counter=0;
    while(!qu.empty())
    {
      int node=qu.front();
      qu.pop();
      counter++;

      for(auto it:adjls[node])
      { indegree[it]--;
        if(indegree[it]==0) qu.push(it);
      }
    }
  // If counter < n, a cycle exists
    if(counter<n) return 1;
    
    return 0;
}
// Time Complexity:O(V+E)
// Space Complexity:O(V+E)
