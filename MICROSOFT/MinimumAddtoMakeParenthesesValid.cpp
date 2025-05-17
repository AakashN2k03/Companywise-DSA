// LEETCODE: Minimum Add to Make Parentheses Valid

// Pattern : Valid Parentheses / Expression Matching	


class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<int> st;
        for(char ch:s)
        {
            if(ch=='(') st.push(ch);
            else
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop(); // matched pair
                }
                else{
                    count++; //unmatched pair;
                }
            }
        }
        count+=st.size(); // Remaining unmatched '(' in the stack
        return count;
        
    }
};
//  Time Complexity: O(n)
//  Space Complexity: O(n)
