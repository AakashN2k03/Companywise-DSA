// CODE360: First and Last Position of an Element In Sorted Array
int first(vector<int>&arr,int n,int k)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==k) 
        { ans=mid;
        high=mid-1;
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
int second(vector<int>&arr,int n,int k)
{
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==k)
        { ans=mid;
         low=mid+1;
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first_index=first(arr,n,k);
    int second_index=second(arr,n,k);
    if(first_index==-1 || second_index==-1) return {-1,-1};
 return {first_index,second_index};

}
Time complexity=O(logn)+O(logn)
Space complexity=O(1)

