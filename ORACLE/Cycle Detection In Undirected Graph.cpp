// CODE360: Cycle Detection In Undirected Graph

// Pattern  - DFS Traversal and BFS

#include<bits/stdc++.h>
using namespace std;
bool bfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adjls) {
    vis[node] = 1;
    queue<pair<int, int>> qu;
    qu.push({node, parent});
    
    while (!qu.empty()) {
        int current_node = qu.front().first;
        int parent_node = qu.front().second;
        qu.pop();

        for (auto it : adjls[current_node]) {
            if (!vis[it]) {
                vis[it] = 1;
                qu.push({it, current_node});
            } else if (it != parent_node) {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>>adjls(n+1);
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }
    vector<int>vis(n+1,0);

    queue<pair<int,int>>qu; // current_node,parent;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
             if(bfs(i,-1,vis,adjls)) return "Yes";
        }
    }
    return "No";
}
// Time Complexity:O(N+v)
// Space Complexity:O(N+v)



// DFS
//GFG Undirected Graph Cycle

class Solution {
  public:
    bool dfs(int node,int parent,vector<int>& vis, vector<vector<int>> & adjls)
    {
        vis[node]=1;
        
        for(auto it:adjls[node])
        {
            if(!vis[it])
            {
                if(dfs(it,node,vis,adjls)) return true;
            }
            else if(it!=parent) return true; //cycle detection
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
      vector<vector<int>> adjls(V);
      for(auto edge:edges)
      {
          int u=edge[0];
          int v=edge[1];
          adjls[u].push_back(v);
          adjls[v].push_back(u);
      }
      vector<int>vis(V,0);
      
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              if(dfs(i,-1,vis,adjls)) return true;
          }
      }
      return false;
    }
};
// Time Complexity:O(N+v)
// Space Complexity:O(N+v)
