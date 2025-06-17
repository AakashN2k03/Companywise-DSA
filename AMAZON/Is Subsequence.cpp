// LEETCODE: 392. Is Subsequence

// Pattern  : Subsequence Based

class Solution {
public:
    int LCS(int index1, int index2, string &s, string &t, vector<vector<int>> &dp) {
        if (index1 < 0 || index2 < 0) return 0;
        
        if (dp[index1][index2] != -1) return dp[index1][index2];
        
        if (s[index1] == t[index2]) {
            return dp[index1][index2] = 1 + LCS(index1 - 1, index2 - 1, s, t, dp);
        }
        
        return dp[index1][index2] = max(
            LCS(index1, index2 - 1, s, t, dp),
            LCS(index1 - 1, index2, s, t, dp)
        );
    }

    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        
        if (s == "") return true; //edge case 1
        if (t == "") return false; //edge case 2
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = LCS(n - 1, m - 1, s, t, dp);
        
        return ans == n; //edge case 3
    }
};

// Time Complexity:O(N * M)
// Space Complexity:O(N * M)

// NOTE:
// Edge Case 1 : s = "", t = ""
// ➤ Meaning: Both strings are empty.
// 🔹 A blank string is always a subsequence of a blank string.

// Output → true

// Edge Case 2 : s = "", t = "abc"
// ➤ Meaning: We're checking if an empty string is a subsequence of a non-empty string.
// 🔹 An empty string is always a subsequence of any string.

// Output → true

// Edge Case 3 : Case 3: s = "abc", t = ""
// ➤ Meaning: We're checking if a non-empty string is a subsequence of an empty string.
// 🔹 A non-empty string cannot be a subsequence of an empty string.

// Output → false
