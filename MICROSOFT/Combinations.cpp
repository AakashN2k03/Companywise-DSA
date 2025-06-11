// LEETCODE: 77. Combinations

// Pattern :  Combinations

class Solution {
public:
    void helper(int start,int n,int k,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(temp.size()==k) 
        {
            ans.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            helper(i+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>>ans;
     vector<int>temp;
     helper(1,n,k,temp,ans);
     return ans;   
    }
};
// Time Complexity: O(C(n, k) × k)
// Space Complexity: O(k)

// WHY Time Complexity:O(C(n, k) × k)
// Example: If n = 4, k = 2, then C(4,2) = 6, and each combination has 2 elements → O(6 × 2) = O(12)
