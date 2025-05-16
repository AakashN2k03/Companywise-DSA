// LEETCODE: 1695. Maximum Erasure Value 

// Pattern : Variable Size Window

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l,r,n;
        n=nums.size();
        l=r=0;
        int sum=0;
        int maxi=-1e9;
        unordered_map<int,int>mpp;
        while(r<n)
        {
            sum+=nums[r];
            mpp[nums[r]]++;
            while(mpp[nums[r]]>1)
            {   mpp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            maxi=max(maxi,sum);
            r++;
        }
        return maxi;
    }
};
//Time complexity: o(n)
//Space complexity:o(n)
