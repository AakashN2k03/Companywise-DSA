// CODE360: Unique Paths II

// Pattern -  DP on Grids

int MOD=1e9+7;
int fn(int i,int j,vector< vector< int> > &mat,vector< vector< int> > &dp)
{
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int up=fn(i-1,j,mat,dp);
    int left=fn(i,j-1,mat,dp);

    return dp[i][j]=(up+left)%MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return fn(n-1,m-1,mat,dp);
}

// TIME COMPLEXITY: O(N*M)
// SPACE COMPLEXITY:O(N*M)
