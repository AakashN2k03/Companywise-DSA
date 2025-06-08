// 78. Subsets

// Pattern : Subsets / Power Set

class Solution {
public:
    void comb(int index,vector<int>& nums,vector<vector<int>>&ans,vector<int>& temp)
    {
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]); //pick
            comb(i+1,nums,ans,temp);
            temp.pop_back(); //not pick
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        comb(0,nums,ans,temp);
      
        return ans;
    }
};
// Time Complexity:O(2^n) 
// Space Complexity:O(n) ( stack space )
