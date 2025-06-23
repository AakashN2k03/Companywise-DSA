// LEETCODE: 516. Longest Palindromic Subsequence

 // Pattern 2 : LCS

class Solution {
public:
    int LCS(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp) {
        if (index1 < 0 || index2 < 0) return 0;
        if (dp[index1][index2] != -1) return dp[index1][index2];

        if (text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + LCS(index1 - 1, index2 - 1, text1, text2, dp);
        }
        return dp[index1][index2] = max(LCS(index1 - 1, index2, text1, text2, dp),
                                        LCS(index1, index2 - 1, text1, text2, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return LCS(n - 1, n - 1, s, s2, dp);
    }
};

// Time Complexity:(n*m);
// Time Complexity:(n*m);
