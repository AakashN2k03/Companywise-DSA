// LEETCODE: 200. Number of Islands

class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> qu; // ROW , COL
         qu.push({row,col});
         int neighbour_row_Arr[]={-1,0,1,0};
         int neighbour_col_Arr[]={0,-1,0,1};

         while(!qu.empty())
         {
            int row=qu.front().first;
            int col=qu.front().second;
            qu.pop();

            for(int i=0;i<4;i++)
            {
                    int neighbour_row=row+neighbour_row_Arr[i];
                    int neighbour_col= col+neighbour_col_Arr[i];
                    if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m &&
                    grid[neighbour_row][neighbour_col]=='1' && !vis[neighbour_row][neighbour_col])
                    {
                        vis[neighbour_row][neighbour_col]=1;
                        qu.push({neighbour_row,neighbour_col});
                    }
                
            }
         }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int counter=0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {   counter++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return counter;
        
    }
};
// ✅ Time Complexity: O(n × m)
// ✅ Space Complexity:
// visited array: O(n × m)

// queue (in worst case): O(n × m) if the entire grid is one big island.
// So, space complexity is also:O(n × m)


// DFS


#include <bits/stdc++.h> 
void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,int m)
{
    vis[row][col]=1;
    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};

    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
        {
            dfs(nrow,ncol,vis,grid,n,m);
        }

    }

}
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>>vis(n,vector<int>(m,0));
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {   counter++;
                dfs(i,j,vis,grid,n,m);
            }
        }
    }
    return counter;
}
// ✅ Time Complexity: O(n × m)
// ✅ Space Complexity:
// visited array: O(n × m)
