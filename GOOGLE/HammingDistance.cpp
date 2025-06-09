// LEETCODE:461. Hamming Distance

// Pattern : Bit Masking & Operations

// NOTE: TO FIND HAMMING DISTANCE BETWEEN TWO INTEGERS
// STEP 1. XOR X AND Y TO FIND NEW NUMBER
// STEP 2. USE COUNTING BITS TECHNIQUE FOR THAT NEW NUMBER
// STEP 3. RETURN THE COUNT OF 1's

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorr=x^y; 
        int count=0;
        while(xorr!=0)
        {   count++;
            xorr=xorr&(xorr-1);   
        }
        return count;
        
    }
};
// Time complexity:O(1)
// Space complexity:O(1)

// WHY time complexity is O(1) (constant time) ?
// becoz of  32-bit or 64-bit integers — like int or long in C++.
