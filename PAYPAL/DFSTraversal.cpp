// CODE 360: DFS Traversal

vector<int> dfs(int node,vector<int>&vis,vector<vector<int>>&adjls,vector<int>&ans)
{
    vis[node]=1;
    ans.push_back(node);
    
    for(auto it:adjls[node])
    {   
        if(!vis[it])
        {
            dfs(it,vis,adjls,ans);
        }
    }
    return ans;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>adjls(V);
    for(auto edge:edges)
    {   int u=edge[0];
        int v=edge[1];
        adjls[u].push_back(v);
        adjls[v].push_back(u);
    }

    vector<int>vis(V,0);
    vector<vector<int>>result;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {   vector<int>ans;
            dfs(i,vis,adjls,ans);
            result.push_back(ans);
        }
    }
    return result;
}
// Time Complexity: O(V + 2E) = O(V + E)
// Space Complexity: O(V + E)

//NOTE: TOTAL TIME COMPLEXITY
// = O(V + E) [adj list]
// + O(V)     [vis]
// + O(V)     [result]
// + O(V)     [ans]
// + O(V)     [call stack]
// = O(V + E) + O(4V)
// = O(V + E)  
