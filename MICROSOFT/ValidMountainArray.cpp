// LEETCODE: 941. Valid Mountain Array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 1;

        // Walk up
        while (i < n && arr[i] > arr[i - 1]) i++;

        // Peak can't be first or last
        if (i == 1 || i == n) return false;

        // Walk down
        while (i < n && arr[i] < arr[i - 1]) i++;

        return i == n;
    }
};


// Time complexity:O(n)
// Space complexity:O(1)
