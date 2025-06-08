// LEETCODE: 90. Subsets II

// Pattern 1: Subsets / Power Set

class Solution {
public:
    void comb(int index,vector<int>& nums,vector<int>& temp,vector<vector<int>>&ans)
    {
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue; // if duplicates skip the iteration
           temp.push_back(nums[i]);//pick
            comb(i+1,nums,temp ,ans);//not pick
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        comb(0,nums,temp,ans);
        return ans;
    }
};
// Time Complexity:O(2^n) 
// Space Complexity:O(n) ( stack space )
