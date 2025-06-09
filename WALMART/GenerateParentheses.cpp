// LEETCODE: 22. Generate Parentheses

 // Pattern : Subsets / Power Set

class Solution {
public:
    void helper(string res,int open,int close,vector<string>& ans,int n)
    {
        if(open==n && close==n) // if open and close brackets count same ,i.e equal to n
        {
            ans.push_back(res);
            return;
        }
        if(open<n) // open is less than n , then close also less than n
        {
            helper(res+'(',open+1,close,ans,n);
        }
         if(open>close) // open brackets always higher so that we can add close brackets,
        {
            helper(res+')',open,close+1,ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper("",0,0,ans,n);
        return ans;
    }
};

// Time Complexity: O(4^n / √n)
// Space Complexity:O(4^n / √n × n)
