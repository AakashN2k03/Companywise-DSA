// LEETCODE: 2104. Sum of Subarray Ranges

// Pattern : Monotonic Stack (Min/Max Ranges)

class Solution {
private:
    // Sum of subarray minimums
    long long sumSubarrayMins(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> st;

        // Previous Less Element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Less or Equal Element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }

    // Sum of subarray maximums
    long long sumSubarrayMaxs(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal Element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        // Sum of subarray maximums - sum of subarray minimums
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
// Time Complexity = O(n) + O(n) + O(n) + O(n) + O(n) = O(5n) →  O(n)
// space Complexity = O(n) + O(n) + O(n) + O(n) + O(n) + O(n) + O(n) + O(n)= O(8n) = O(n) 
