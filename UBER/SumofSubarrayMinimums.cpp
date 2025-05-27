// LEETCODE: 907. Sum of Subarray Minimums

// Pattern : Monotonic Stack (Min/Max Ranges)

class Solution {
public:
    // Function to find Previous Smaller Element (PSE)
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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = int(1e9 + 7);

        // Find Previous Smaller Element (PSE) and Next Smaller Element (NSE)
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);

        long long sum = 0;

        // Calculate the contribution of each element
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (right * left % mod) * arr[i] % mod) % mod;
        }

        return sum;
    }
};
// Time Complexity = O(n) + O(n) + O(n) = O(3n) →  O(n)
// space Complexity = O(n) + O(n) + O(n) + O(n) = O(4n) = O(n) 
