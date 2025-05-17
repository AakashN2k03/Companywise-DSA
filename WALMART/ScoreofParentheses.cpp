// LEETCODE : 856. Score of Parentheses

// Pattern : Valid Parentheses / Expression Matching

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;              // Stack to manage nested scores
        st.push(0);                 // Initial outer context

        for (char ch : s) {
            if (ch == '(') {
                st.push(0);         // New context for new '('
            } else {
                int inner = st.top(); st.pop();       // Get inner score
                int outer = st.top(); st.pop();       // Get outer score
                st.push(outer + max(2 * inner, 1));   // Apply rule and push result
            }
        }

        return st.top();            // Final score
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)
