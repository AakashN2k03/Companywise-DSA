// LEETCODE: 47. Permutations II

// Pattern : Permutations
  
class Solution {
public:
    void perm(int index,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {   ans.push_back(nums);
            return;
        }
        unordered_set<int> used_element;
        for(int i=index;i<nums.size();i++)
        {
            if(used_element.count(nums[i])) continue;// skip already tried elements at this index level
            used_element.insert(nums[i]);
            
            swap(nums[index],nums[i]);
            perm(index+1,nums,ans);
            swap(nums[index],nums[i]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        perm(0,nums,ans);
        return ans;
    }
};
// Time Complexity:O(n*n!)
// Space Complexity:O(N) (stack space)
