// LEETCODE:227. Basic Calculator II

// Pattern: Stack Simulation (Custom Logic)

class Solution {
public:
    int calculate(string s) {
        int num=0;
        char last_sign='+'; // using '+' is safe to add numbers in stack, using other operators produce unexpected behaviour
        stack<int>st;
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(isdigit(ch))
            {
                num=num*10+(ch-'0'); //multiply 10 is needed if it is two or more digit numbers. Eg:23
            }
          
            // c != ' ':This ignores spaces. Since the input string can contain spaces (e.g., " 3 + 5 / 2 "), we don't want to process them.
            //i==n-1    :This ensures we don’t miss the last number. eg:= "3+2":

            if((!isdigit(ch) && ch!=' ') || (i==n-1))
            {
                if(last_sign=='+')
                {
                    st.push(num);
                }
                else if(last_sign=='-')
                {
                    st.push(-num);
                }
                else if(last_sign=='*')
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp*num);
                }
                else if(last_sign=='/')
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp/num);
                }
                last_sign=ch;
                num=0;
            }
        }
        int result=0;
       while(!st.empty())
       {
            result+=st.top();
            st.pop();
       } 
       return result;
    }
};
// Time Complexity:O(N)
// Space Complexity:O(N)
