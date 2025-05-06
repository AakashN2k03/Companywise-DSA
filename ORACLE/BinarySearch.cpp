// CODE360: Binary Search
int search(vector<int> &nums, int target) {
    int low,high;
    low=0;
    high=nums.size()-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)
