// CODE360: Find the Number of Provinces

// Pattern  - DFS Traversal and BFS

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<unordered_set<int>>& adjls)
{
    vis[node]=1;
    for(auto neighbour:adjls[node])
    {
        if(!vis[neighbour]) dfs(neighbour,vis,adjls);
    }

}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
   vector<unordered_set<int>>adjls(n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(roads[i][j]==1 && i!=j)
            {   
                adjls[i].insert(j);
                adjls[j].insert(i);

            }
        }
    }
    vector<int>vis(n,0);
    int counter=0;

    for(int i=0;i<n;i++)
    {
         if(!vis[i])
        {
            counter++;
            dfs(i,vis,adjls);
        }
        
    }
    return counter;

}
// Time Complexity:O(n^2)
// Space Complexity:O(n^2)
