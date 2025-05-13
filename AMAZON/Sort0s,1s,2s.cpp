// CODE 360:  Sort 0s, 1s, 2s

// The Dutch National Flag Algorithm is specifically designed to work when the array contains exactly three distinct types of elements or values.
// In some case,it will work for  below 3 elements too
vector<int> Sort0s1s2s(vector<int> &arr){
	// DUTCH FLAG ALGORITHM
	int low,mid,high;
	int n=arr.size();
	low=mid=0;	
	high=n-1;
	while(mid<=high)
	{
		if(arr[mid]==0) // move to low
		{   swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid]==1) mid++; //skip
		else{
			swap(arr[mid],arr[high]); // move to high
			high--;
		}
	}
	return arr;
}
//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(1)

// NOTE:If the array has more than 3 distinct values (e.g., [0, 1, 2, 3] or [a, b, c, d]), the standard Dutch National Flag logic doesn’t know how to handle the 4th value, 
// because it’s only built for three categories.
