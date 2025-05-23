// LEETCODE: 1047. Remove All Adjacent Duplicates In String

// Pattern : Stack Simulation (Custom Logic)

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        for(char ch:s)
        {
            if(!st.empty() && st.top()==ch)
            {
                st.pop();
            }
            //else if (st.empty() || st.top()!=ch) // can use this too
            else
            {
            st.push(ch);

            }
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
//  Time complexity = O(N) + O(N) + O(N) = O(3N) => O(N).
//  Space complexity: O(N)
