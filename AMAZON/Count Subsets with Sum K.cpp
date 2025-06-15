// CODE360: Count Subsets with Sum K

 // Pattern: 0/1 Knapsack Pattern (PICK/NOT PICK)
   
int MOD=1e9+7;
int fn(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; // two options: take or not take the 0
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        
        int not_pick = fn(index - 1, target, arr, dp);
        
        int pick = 0;
        if (arr[index] <= target) {
            pick = fn(index - 1, target - arr[index], arr, dp);
        }
        
        return dp[index][target] = (pick + not_pick)% MOD;
    }
  int findWays(vector<int>& arr, int target)
{ int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(n - 1, target, arr, dp);
}
// Time Complexity	: O(n * k)
// Space Complexity: O(n * k) + O(n)
