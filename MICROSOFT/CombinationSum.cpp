// LEETCODE:39. Combination Sum

// Pattern : Combination

class Solution {
public:
    void comb(int index,vector<int>& candidates, int target,vector<int>& temp,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(index==candidates.size()) return;

        //pick;
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            comb(index,candidates,target-candidates[index],temp,ans);
            temp.pop_back();
        }

        //not pick;
        comb(index+1,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        comb(0,candidates,target,temp,ans);
        return ans;
    }
};

// Time Complexity:O(2^target)
// Space Complexity:O(N) (stack space)
