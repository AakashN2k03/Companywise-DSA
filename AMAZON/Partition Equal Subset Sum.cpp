// LEETCODE: 416. Partition Equal Subset Sum

// PATTERN: 0/1 Knapsack Pattern (PICK/NOT PICK)

class Solution {
public:
    bool recurse(int index,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(index==0) return nums[0]==target;
        if(dp[index][target]!=-1) return dp[index][target];

        bool not_pick=recurse(index-1,target,nums,dp);
        bool pick=false;
        if(nums[index]<=target)
        {
            pick=recurse(index-1,target-nums[index],nums,dp);
        }
        return dp[index][target]=pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum+=nums[i];
        }
        if(total_sum%2!=0) return false;
        int target=total_sum/2;
         vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return recurse(n-1,target,nums,dp);
    }
};
// ⏰ Time Complexity: O(n × target) + O(n) (for loop ) = O(n × target)
// 🧠 Space Complexity: O(n × target) +  O(n) (stack space)
