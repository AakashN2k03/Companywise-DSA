// LEETCODE: 190. Reverse Bits

// Pattern : Clever Bit Tricks

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++)
        {
            res=res<<1; 
            res|=(n&1);
            n=n>>1;
        }
        return res;
        
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)

// INTUITION:
// res <<= 1 – Shift res left to make space for the next bit.
// res |= (n & 1) – Extract the last bit of n and insert it into res.
// n >>= 1 – Move to the next bit of n by shifting it right.
