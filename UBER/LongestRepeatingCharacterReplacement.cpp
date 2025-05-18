// CODE 360: Longest Repeating Character Replacement 

// Pattern : Count/Score Based Tracking

int longestRepeatingSubstring(string &s, int k) {
    int l = 0, r = 0;
    int n = s.length();
    int maxlen = 0;
    int freq = 0;  // Tracks the count of the most frequent character in the window
    unordered_map<int, int> mpp;  // Frequency map of characters in the current window

    while (r < n) {
        mpp[s[r]]++;  // Add current character to the window
        freq = max(freq, mpp[s[r]]);  // Update the max frequency character in the window

        // If replacements needed > k, shrink the window from the left
        while ((r - l + 1) - freq > k) {
            mpp[s[l]]--;  // Remove the leftmost character from window
            l++;          // Shrink window
        }

        // Update max length of valid window
        maxlen = max(maxlen, r - l + 1);

        r++;  // Expand window to the right
    }

    return maxlen;
}
// Time Complexity: O(n)
// Space ComplexityO(1) for English uppercase letters (since only 26 letters)
