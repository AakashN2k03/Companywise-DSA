// CODE360: Triangle

// Pattern 5-  DP on Grids

#include <bits/stdc++.h> 
int fn(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n)
{
	// if(i>n-1 && j>n-1) return 1e9;  Unnecessary since triangle behaviour prevent out of bound error
	if(i==n-1) return triangle[i][j]; // any column in last row
	if(dp[i][j]!=-1) return dp[i][j];


	int down=triangle[i][j]+fn(i+1,j,triangle,dp,n);
	int bottom_right_diagonal=triangle[i][j]+fn(i+1,j+1,triangle,dp,n);

	return dp[i][j]=min(down,bottom_right_diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return fn(0,0,triangle,dp,n);
}
// Time Complexity:  O(n^2)
// Space Complexity: O(n^2)
