// LEETCODE: 46. Permutations

// Pattern : Permutations
  
class Solution {
public:
    void perm(int index,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            perm(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>>ans;
     perm(0,nums,ans);
     return ans;   
    }
};
// Time Complexity:O(n * n!) 
// Space Complexity:O(n) ( stack space )

// WHY ime Complexity:O(n * n!) not n! alone?
//   becoz for eg Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] Then, 3*3! = n *n!
