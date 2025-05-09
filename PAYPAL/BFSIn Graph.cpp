// CODE360:  BFS in Graph

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int>vis(n,0);
    queue<int>qu;
    qu.push(0);
     vis[0]=1;
    vector<int>bfs;
    while(!qu.empty())
    {
        int node=qu.front();
        bfs.push_back(node);
        qu.pop();
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            { vis[it]=1;
                qu.push(it);
            }
        }
    }
    return bfs;
}
// TIME COMPLEXITY:O(E+V)
// SPACE COMPLEXITY:O(E+V) for adjls
