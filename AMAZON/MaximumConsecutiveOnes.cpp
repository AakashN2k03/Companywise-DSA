// CODE 360:  Maximum Consecutive Ones

int consecutiveOnes(vector<int>& arr){
    int n=arr.size();
    int count=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
        }
    }
    return maxi;
}
// Time Complexity: O(n) 
// Space Complexity: O(1)
