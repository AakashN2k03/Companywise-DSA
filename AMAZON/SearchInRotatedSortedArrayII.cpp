// LEETCODE: 81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n,low,high,mid;
        n=arr.size();
        low=0,high=n-1;
   
        while(low<=high)
        {
           int mid=(low+high)/2;
           if(arr[mid]==target) return true;
           if(arr[low]==arr[mid] && arr[mid]==arr[high])
           {
           low++;
           high--;
            continue;
           }
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=target && target<=arr[mid])
                {
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(arr[mid]<=target && target<=arr[high])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
        
    }
};
// TIME COMPLEXITY:
// Best case (with no duplicates): O(log n)
// Worst case (with duplicates): O(n)

// SPACE COMPLEXITY: O(1)
