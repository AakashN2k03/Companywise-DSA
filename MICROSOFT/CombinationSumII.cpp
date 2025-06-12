// LEETCODE: 40. Combination Sum II

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
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            fn(i+1, candidates, target - candidates[i], temp, ans); 
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        fn(0,candidates,target,temp,ans);
        return ans;
        
    }
};
// Time Complexity:O(2^n) 
// Space Complexity:O(n) ( stack space )
