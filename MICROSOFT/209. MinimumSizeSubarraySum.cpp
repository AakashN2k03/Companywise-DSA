// LEETCODE: 209. Minimum Size Subarray Sum 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l,r,n;
        n=nums.size();
        l=r=0;
        int sum=0;
        int mini=INT_MAX;
        while(r<n)
        {
              sum+=nums[r];
              while(sum>=target)
              { 
                  sum-=nums[l];
                  mini=min(mini,(r-l+1));
                  l++;
              }
              r++;
        }
        return mini==INT_MAX?0:mini;
    }
};
//// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(1)
