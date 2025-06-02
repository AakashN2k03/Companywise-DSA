// LEETCODE: Peak Index in a Mountain Array 

// Pattern : Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low,mid,high;
        low=0;
        int n=arr.size();
        high=n-1;

        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]>arr[mid+1])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};

// Time complexity:O(logn)
// Space complexity:O(1)
