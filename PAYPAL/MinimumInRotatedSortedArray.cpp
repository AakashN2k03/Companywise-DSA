// CODE 360:  Find Minimum in Rotated Sorted Array
int findMin(vector<int>& arr)
{
	int low, high,n;
	n=arr.size();
	low=0;
	high=n-1;
	int ans=1e9;
	while(low<=high)
	{
		int mid=(low+high)/2;
    //INCASE IF ARR HAS DUPLICATE ELEMENTS
    
   // if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
   //          // duplicates case: can't determine sorted half
   //          ans = min(ans, arr[mid]);
   //          low++;
   //          high--;
   //      }
    
		// left sorted
		if(arr[low]<=arr[mid])
		{
			ans=min(ans,arr[low]);
			low=mid+1;
		}
		// right sorted

		else{
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;
}

// Time Complexity
// Best case: O(log n) — when no duplicates  
// Worst case: O(n) — when all elements are duplicates and you only shrink by 1 each time
// SPACE COMPLEXITY: O(1)
