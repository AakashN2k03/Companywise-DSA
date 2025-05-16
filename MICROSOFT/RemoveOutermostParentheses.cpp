// LEETCODE: 1021. Remove Outermost Parentheses 

// Pattern : Valid Parentheses / Expression Matching

class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string res="";
        for(char ch:s)
        {
            if(ch=='(')
            {
                if(balance>0) res+=ch;
                balance++;
            }
            else{
                balance--;
                if(balance>0) res+=ch;
            }
        }
        return res;
    }
};
//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(N)
