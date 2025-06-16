// CODE360:  0 1 Knapsack

// Pattern: 0/1 Knapsack Pattern (PICK/NOT PICK)
  
#include <bits/stdc++.h> 
int knapsack_value(int index,vector<int> value,vector<int> weight,int maxWeight,vector<vector<int>>&dp)
{
	if(index==0)
	{
		if(weight[index]<=maxWeight) return value[index];
		return 0;
	}
	if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];

	int not_pick=knapsack_value(index-1,value,weight,maxWeight,dp);
	int pick=0;
	if(weight[index]<=maxWeight)
	{
		pick=value[index]+knapsack_value(index-1,value,weight,maxWeight-weight[index],dp);
	}

	return dp[index][maxWeight]=max(pick,not_pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return knapsack_value(n-1,value,weight,maxWeight,dp);
}
// Time Complexity:O(N * maxWeight)
// Space Complexity:O(N * maxWeight)
