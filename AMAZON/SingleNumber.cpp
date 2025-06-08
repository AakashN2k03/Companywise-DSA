// LEETCODE:136. Single Number

// Pattern : Bit Masking & Operations

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int num:nums)
        {
            res^=num;
        }
        return res;
        
    }
};
// Time Complexity:O(n) 
// Space Complexity:O(1)
