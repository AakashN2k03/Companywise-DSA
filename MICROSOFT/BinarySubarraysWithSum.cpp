// LEETCODE: 930. Binary Subarrays With Sum

// PATTERN :  Exactly K Distinct Elements (VARIABLE SIZED)

// NOTE:  formula => Exactly(K) = AtMost(K) - AtMost(K - 1)
        
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>& nums, int goal)
    {
        int  l,r,n,sum,count;
        n=nums.size();
        l=r=0;
        sum=0;
        count=0;
        if(goal<0) return 0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1); // since we need count of subarrays
            r++;
        }
        return count;
    }
};
//TIME COMPLEXITY: o(n)+o(n)=o(2n)=O(N)
//SPACE COMPLEXITY:O(1)
