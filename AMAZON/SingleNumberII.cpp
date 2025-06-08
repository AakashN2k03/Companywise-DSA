// Leetcode: 137. Single Number II

// Bitwise Bucket Manipulation 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            // Update 'ones' with the current num, but remove it if it's already in 'twos'
            ones = (ones ^ num) & ~twos;

            // Update 'twos' with the current num, but remove it if it's now in 'ones'
            twos = (twos ^ num) & ~ones;
        }
        return ones; // Only the unique element remains in 'ones'
    }
};

// Time complexity:O(N)
// Space complexity:O(1)
