// LEETCODE: 342. Power of Four

// Pattern : Clever Bit Trick

// NOTE: THE NUMBER WHICH IS A POWER OF 4 ,WHEN DIVISIBLE BY 3 WILL ALWAYS LEAVE REMAINDER AS 1

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n>0 && (n & n-1)==0 && (n%3==1))?true:false;
    }
};

// Time Compelxity:O(1)
// Space Compelxity:O(1)
