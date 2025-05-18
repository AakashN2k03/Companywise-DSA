// LEETCODE: 1493 Longest Subarray of 1's After Deleting One Element

// PATTERN: Count/Score Based Tracking

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l,r,maxlen,n,zeros;
        n=nums.size();
        maxlen=0;
        l=r=0;
        zeros=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                zeros++;
            }
            while(zeros>1)
            {
                if(nums[l]==0)
                {
                    zeros--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
     return maxlen-1;   
    }
};
// Time Complexity = O(n)
// Space Complexity = O(1)
