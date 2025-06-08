// LEETCODE: Single Number III

// PATTERN: Bitwise Bucket Manipulation 

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        // Step 1: XOR all numbers to get x ^ y (where x and y are the two unique numbers)
        for (int num : nums) {
            xorr ^= num;
        }

        // Step 2: Find the rightmost set bit in xorr
        // This bit is different between the two unique numbers
        int right_most_bit = xorr & -xorr;

        int b1 = 0, b2 = 0;

        // Step 3: Divide numbers into two groups based on that bit
        // XOR separately to isolate x and y
        for (int num : nums) {
            if (num & right_most_bit)
                b1 ^= num;  // Group with bit set
            else
                b2 ^= num;  // Group with bit not set
        }

        // Step 4: Return the two unique numbers
        return {b1, b2};
    }
};

// Time complexity:O(N)
// Space complexity:O(1)

// HOW TO FIND -xorr?
//   1. Invert the xorr
//   2. Add 1 to xor
