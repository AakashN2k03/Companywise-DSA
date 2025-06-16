// LEETCODE: 494. Target Sum 

// Pattern: 0/1 Knapsack Pattern (PICK/NOT PICK)
  
class Solution {
public:
 int fn(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; // dry run ,arr = {0}, target = 0 and arr = {0,0}, target = 0

            if (target == 0 || arr[0] == target) return 1; //dry run arr = {5}, target = 0 

            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        
        int not_pick = fn(index - 1, target, arr, dp);
        
        int pick = 0;
        if (arr[index] <= target) {
            pick = fn(index - 1, target - arr[index], arr, dp);
        }
        
        return dp[index][target] = pick + not_pick;
    }
    int countPartitions(vector<int>& arr, int d) {
        int tot_sum=0;
        for(int num:arr) tot_sum+=num;
        
        if(tot_sum-d<0 || (tot_sum-d)%2!=0) return 0;  // can use this too (totalSum + d) % 2!= 0
        
        int n = arr.size();
        int target=(tot_sum-d)/2; // can use this too (totalSum + d) / 2
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(n - 1, target, arr, dp);
     
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     return countPartitions(nums,target);
        
    }
};
// Time Complexity:O(N * target)
// Space Complexity:O(N * target)

// INTUITION 
// sum1 + sum2 = totalSum
//sum1=totalSum-sum2
// sum1 - sum2 = d
// so, totalSum-sum2-sum2=d
// which turns out to be sum2=(tot_sum-d)/2;
