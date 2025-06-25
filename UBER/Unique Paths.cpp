// LEETCODE: 62. Unique Paths

// Pattern: DP on Grids

// FROM BOTTOM TO TOP

class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up=fn(i-1,j,dp);
        int left=fn(i,j-1,dp);

        return dp[i][j]=up+left;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,dp);
    }
};
// Time Complexity:O(m * n)
// Space Complexity:O(m * n)



// FROM TOP TO BOTTOM

#include <bits/stdc++.h> 
 int fn(int i,int j,vector<vector<int>>&dp,int m,int n)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>m-1 || j>n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int down=fn(i+1,j,dp,m,n);
        int right=fn(i,j+1,dp,m,n);

        return dp[i][j]=down+right;

    }
   
int uniquePaths(int m, int n) {
	 vector<vector<int>>dp(m,vector<int>(n,-1));
     return fn(0,0,dp,m,n);
}

// Time Complexity:O(m * n)
// Space Complexity:O(m * n)
