// LEETCODE: 5. Longest Palindromic Substring

// Pattern: Two Pointer

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; ++i) {
            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) { // r - l + 1 > maxLen it will produce the first palindrome, r - l + 1 >= maxLen next longest plaindrome, try this problem in code360
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }

            // Even length
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
        }

        return s.substr(start, maxLen);
    }
};

// ⏱️ Time Complexity: O(n²)
// 🧠 Space Complexity: O(1)
