// CODE 360:  Valid Parentheses 
bool isValidParenthesis(string s)
{
    stack<int>st;
    int n=s.length();
    for(char ch:s)
    {
        if(ch=='(' || ch=='{' || ch=='[' )
        {
            st.push(ch);
        }
        else{
            if(st.empty()) return false;

            char top_element=st.top();
            if((ch=='(' && top_element!=')') || (ch=='{' && top_element!='}')||(ch=='[' && top_element!=']')) return false;

            st.pop();
            
        }
    }
    return st.empty();

}

// Time Complexity: O(n)
// Space Complexity: O(n)
