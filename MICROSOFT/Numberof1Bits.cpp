LEETCODE: 191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0)
        {   count++;
            n=n&n-1;

        }
       return count; 
    }
};
// Time Complexity:O(1)
// Space Complexity:O(1)
