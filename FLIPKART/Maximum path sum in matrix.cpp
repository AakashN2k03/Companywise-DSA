// GFG: Maximum path sum in matrix

// Pattern  -  DP on Grids

class Solution {
  public:
    int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m)
{
    if(i>n-1 || j<0 || j>m-1) return -1e9; // why not use i<0 because in this i will be incremented only , not decremented
    if(i==n-1 ) return grid[i][j]; // any column in the last row

    if(dp[i][j]!=-1) return dp[i][j];

    int diagonal_left=grid[i][j]+fn(i+1,j-1,grid,dp,n,m);
    int down=grid[i][j]+fn(i+1,j,grid,dp,n,m);
    int diagonal_right=grid[i][j]+fn(i+1,j+1,grid,dp,n,m);

    return dp[i][j]=max({diagonal_left,diagonal_right,down});

}
    int maximumPath(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxPath = -1e9;
    for (int j = 0; j < m; j++) {
        maxPath = max(maxPath, fn(0, j, grid, dp, n, m));
    }
    return maxPath;
      
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
