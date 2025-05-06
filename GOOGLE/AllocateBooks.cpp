// CODE 360:  Allocate Books 
int distirbution_of_books(vector<int>& arr ,int mid,int n)
{
    int student=1;
    int page_count=0;

    for(int i=0;i<n;i++)
    {
       if(page_count+arr[i]<=mid)
       {
           page_count+=arr[i];
       }
       else{
           student++;
           page_count=arr[i];
       }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int maxi,sum;
    maxi=-1e9;
    sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }
    int low,high;
    low=maxi;
    high=sum;

    while(low<=high)
    {
        int mid=(low+high)/2;
        int result=distirbution_of_books(arr,mid,n);
        if(result>m)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

// TIME COMPLEXITY=O(n * log(sum - maxi+1))     (sum-max+1 denotes range of elements between them) and O(N) for pagecount loop in fucntion  distirbution_of_books
// SPACE COMPLEXITY=O(1)
