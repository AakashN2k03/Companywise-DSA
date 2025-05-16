// LEETCODE: 643. Maximum Average Subarray I

// Pattern : Fixed Size Window

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l,r,n;
        double sum=0;
        l=r=0;
        n=nums.size();
        double maxi=-1e9;
        while(r<n)
        {
            sum+=nums[r];
            if(r-l+1>=k)
            {  double avg=sum/k;
                maxi=max(maxi,avg);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return maxi;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1) 
