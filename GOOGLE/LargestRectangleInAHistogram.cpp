// CODE360: Largest rectangle in a histogram

// Pattern : Monotonic Stack (Min/Max Ranges)

// MOST OPTIMIZED APPROACH
#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& heights) {
    int n = heights.size();  
    stack<int> st;                                
    int maxi = 0;            

    // Traverse all bars in the histogram
    for (int i = 0; i < n; i++) {
        // If the current bar is shorter than the bar at top of stack,
        // it means we've found the Next Smaller Element (NSE) for the bar at the top
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int element = st.top();  // Index of the taller bar
            st.pop();                // Pop it to calculate area

            // After popping, the new top is the Previous Smaller Element (PSE)
            int pse = st.empty() ? -1 : st.top();

            int nse = i;  // Current index is the NSE for the popped element
            maxi = max(maxi, heights[element] * (nse - pse - 1));
        }

        // Push the current index to the stack
        // We push indices to keep track of the bars and calculate width later
        st.push(i);
    }

    // Process remaining elements in stack after complete traversal
    // These elements didn't find any smaller bar on the right (NSE), so use n
    while (!st.empty()) {
        int element = st.top();  // Index of remaining taller bar
        st.pop();

        int pse = st.empty() ? -1 : st.top();  // Previous smaller index
        int nse = n;  // No NSE found, so use n as right boundary

        maxi = max(maxi, heights[element] * (nse - pse - 1));  
    }

    return maxi;  
}
//Time complexity:O(N)
//Space complexity:O(N)


// ALTERNATIVE WAY (BRUTE FORCE) -> EASIEST
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
    int largestRectangleArea(vector<int>& heights) {
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
};
// Time Complexity = O(n) + O(n) + O(n) = O(n)
// Space Complexity = O(n) + O(n) + O(n) + O(n) = O(n)
