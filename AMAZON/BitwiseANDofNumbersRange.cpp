// LEETCODE: 201. Bitwise AND of Numbers Range

// Pattern 4: Clever Bit Tricks

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right)
        {
            right=right & (right-1);
        }
        return right;
    }
};
// Time Complexity: O(log n)
// Space Complexity:O(1)
