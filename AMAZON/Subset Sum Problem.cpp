// GFG: Subset Sum Problem

// PATTERN: 0/1 Knapsack Pattern (PICK/NOT PICK)

class Solution {
  public:
    bool recurse(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index == 0) return arr[0] == target;

        if (dp[index][target] != -1) return dp[index][target];

        bool notpick = recurse(index - 1, target, arr, dp);
        bool pick = false;
        if (arr[index] <= target)
            pick = recurse(index - 1, target - arr[index], arr, dp);

        return dp[index][target] = pick || notpick;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return recurse(n - 1, sum, arr, dp);
    }
};
⏰ Time Complexity: O(n × sum)
🧠 Space Complexity: O(n × sum) + O(n)
