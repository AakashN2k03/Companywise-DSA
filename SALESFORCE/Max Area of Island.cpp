// LEETCODE: 695. Max Area of Island

// Pattern  - DFS Traversal and BFS

class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,int m,int & counter)
{
    vis[row][col]=1;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,-1,0,1};

    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {   counter++;
            dfs(nrow,ncol,vis,grid,n,m,counter);
        }

    }

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n,m;
        n=grid.size();
        m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int maxi=0;
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {   counter=1;
                dfs(i,j,vis,grid,n,m,counter);
                maxi=max(maxi,counter);
            }
        }
    }
    return maxi;
    }
};
// ✅ Time Complexity: O(n × m)
// ✅ Space Complexity: O(n × m)
