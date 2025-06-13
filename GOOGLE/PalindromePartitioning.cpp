// LEETCODE: 131. Palindrome Partitioning

// Pattern: Palindrome Partitioning

class Solution {
public:
    void fn(int index,string s,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(index==s.length()) //his checks whether we have reached the end of the string.
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(ispal(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                fn(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    bool ispal(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        fn(0,s,temp,ans);
        return ans; 
        
    }
};
// Time Complexity:O(2^n * n)
// Space Complexity:O(n) (auxillary space)
