// LEETCODE:39. Combination Sum

// Pattern : Combination

class Solution {
public:
    void fn(int index,vector<int>& candidates, int target,vector<int>& temp,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

       for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            fn(i, candidates, target - candidates[i], temp, ans); // not i + 1, because we can reuse
            temp.pop_back();
        }
    }
}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        fn(0,candidates,target,temp,ans);
        return ans;
    }
};
// Time Complexity:O(2^target)
// Space Complexity:O(N) (stack space)
