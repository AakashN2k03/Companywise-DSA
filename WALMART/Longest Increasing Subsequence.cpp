// LEETCODE: 300. Longest Increasing Subsequence

// Pattern  : LIS

class Solution {
public:
    int LIS(int current_index,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(current_index==nums.size()) return 0;
        if(dp[current_index][prev+1]!=-1) return dp[current_index][prev+1];
        int not_pick=LIS(current_index+1,prev,nums,dp);

        int pick=0;
        if(prev==-1 || nums[current_index]> nums[prev])
        {
            pick=1+LIS(current_index+1,current_index,nums,dp);
        }

        return dp[current_index][prev+1]= max(pick,not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp);
    }
};

// Time Complexity:O(n*n+1) => O(n²)
// Space Complexity:O(n*n+1) => O(n²)

// NOTE: WHY n+1,vector<vector<int>>dp(n,vector<int>(n+1,-1)) 
// becoz of prev value ,we use corrdinate change

  // What Is "Coordinate Change" in DP?
// In DP, a coordinate change means mapping an invalid or inconvenient index (like -1) to a valid array index (like 0) by shifting or transforming it.
