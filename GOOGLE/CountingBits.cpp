// LEETCODE: 338. Counting Bits

// Pattern : Bit Masking & Operations

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int count=0;
        for(int i=0;i<=n;i++)
        {
            int num=i;
            while(num!=0)
            {
                count++;
                num=num&(num-1);// Removes the rightmost set bit from num
                //so at some point of time the num become 0
            }
            ans.push_back(count);
            count=0;
        }
      return ans;  
    }
};
// Time Complexity:O(n log n)
// Space Complexity:O(N)
