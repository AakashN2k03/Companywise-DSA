// LEETCODE: 1248. Count Number of Nice Subarrays

// Pattern : Exactly K Distinct Elements (variable size)

//NOTE: SAME AS  930. Binary Subarrays With Sum PROBLEM

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1); 
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
            sum+=nums[r]%2;
            while(sum>goal)
            {
                sum-=nums[l]%2;
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
