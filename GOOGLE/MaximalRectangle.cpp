// LEETCODE: 85. Maximal Rectangle

// Pattern : Monotonic Stack (Min/Max Ranges)

// OPTIMIZED APPROACH

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



// ALTERNATIVE WAY ( BRUTE FORCE ) 

class Solution {
  public:
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1); // Initialize with -1 (no smaller element to the left)
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    // Function to find Next Smaller Element (NSE)
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n); // Initialize with n (no smaller element to the right)
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }
    int largest_rectangle(vector<int>& heights)
    {
         int n=heights.size();
        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
    int maxArea(vector<vector<int>> &matrix) {
        
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int max_rectangle=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1) heights[j]=heights[j]+1;
                else heights[j]=0;
            }
            max_rectangle=max(max_rectangle,largest_rectangle(heights));
        }
       return max_rectangle; 
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(m)
