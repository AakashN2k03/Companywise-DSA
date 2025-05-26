// LEETCODE: 32. Longest Valid Parentheses

//Pattern : Valid Parentheses / Expression Matching

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1); //helps to calculate the length of valid parentheses from the very beginning of the string.
        int maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    maxlen=max(maxlen,i-st.top());
                  
                    //i->current index
                    //st.top()->Index just before the valid segment started
                    //i-st.top()->Length of the current valid substring ending at i
                    // eg dry run this s = "(()())" to know above statements and use of st.pus(-1)
                }
            }
        }
        return maxlen;
        
    }
};
// Time Complexity:O(N)
// Space Complexity:O(N)
