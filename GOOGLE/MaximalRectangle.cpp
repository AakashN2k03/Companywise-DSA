// LEETCODE: 85. Maximal Rectangle

// Pattern : Monotonic Stack (Min/Max Ranges)

class Solution {
public:
    int largest_rectangle(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int element=st.top();
                st.pop();
                int pse=(st.empty())?-1:st.top();
                int nse=i;
                maxi=max(maxi,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int element=st.top();
            st.pop();
            int nse=n;
            int pse=(st.empty())?-1:st.top();
            maxi=max(maxi,heights[element]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int max_rectangle=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') heights[j]=heights[j]+1;
                else heights[j]=0;
            }
            max_rectangle=max(max_rectangle,largest_rectangle(heights));
        }
       return max_rectangle; 
    }
};
//Time complexity: n * O(m + m) = O(n * m)
//Space complexity: O(m) (heights) +  O(m) (stack) =  O(m)
