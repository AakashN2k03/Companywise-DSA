// CODE 360:  Painter's Partition Problem
int painters(vector<int>&boards,int mid,int n)
{
    int painter=1,boards_count=0;
    for(int i=0;i<n;i++)
    {
        if(boards_count+boards[i]<=mid)
        {
            boards_count+=boards[i];
        }
        else{
            painter++;
            boards_count=boards[i];
        }
    }
    return painter;
}
int findLargestMinDistance(vector<int> &boards, int k)
{  int n=boards.size();
    
   if(k>n) return -1;
   int low,high,sum,maxi;
   sum=0;
   maxi=-1e9;
   for(int i=0;i<n;i++)
   {
       sum+=boards[i];
       maxi=max(maxi,boards[i]);
   }

   low=maxi;
   high=sum;

   while(low<=high)
   {
       int mid=(low+high)/2;
       int ans=painters(boards,mid,n);
       if(ans>k) low=mid+1;
       else high=mid-1;
   }
   return low;
}
// TIME COMPLEXITY=O(n * log(sum - maxi+1))    
// SPACE COMPLEXITY=O(1)
