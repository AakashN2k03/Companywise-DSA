// CODE360:  Search In Rotated Sorted Array
int search(int* arr, int n, int key) {
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        
        // check left is sorted
        if(arr[low]<=arr[mid])
        {
          // whether target is present in left side range
          if(arr[low]<=key && key<=arr[mid])
          {  //element exist
              high=mid-1;
          }
          else{
              // element not exist
              low=mid+1;
          }
        }
        // check right is sorted
        else{
            // whether target is present in right side range
          if(arr[mid]<=key && key<=arr[high])
         {   
             //element exist
              low=mid+1;
          }
          else{
              // element not exist
              high=mid-1;
          }
        }
    }
    return -1;
}
TIME COMPLEXITY:O(LOGN)
SPACE COMPLEXITY:O(1)
