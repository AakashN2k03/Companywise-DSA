// GFG: Partitions with Given Difference 

 // Pattern: 0/1 Knapsack Pattern (PICK/NOT PICK)
   
class Solution {
public:
    int recurse(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case handling
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; // Two subsets: pick or not pick 0
            if (target == 0 || arr[0] == target) return 1; // One valid subset
            return 0; // No valid subset
        }

        if (dp[index][target] != -1) return dp[index][target]; 

        int not_pick = recurse(index - 1, target, arr, dp); // Exclude current element

        int pick = 0;
        if (arr[index] <= target) {
            pick = recurse(index - 1, target - arr[index], arr, dp); // Include current element
        }

        return dp[index][target] = pick + not_pick;
    }

    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int total_sum = 0;

        // Calculate total sum of array
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
        }

        // 🔸 Edge Case Check:
        // If (total_sum + d) is odd → subset sum won't be integer → not possible
        // If (total_sum - d) is negative → invalid difference → not possible
        if ((total_sum - d) < 0 || (total_sum - d) % 2 != 0) return 0;

        int target = (total_sum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return recurse(n - 1, target, arr, dp);
    }
};
// Time Complexity:O(N * target)
// Space Complexity:O(N * target)
