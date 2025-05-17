// CODE 360:  Subarrays With ‘K’ Distinct Values

// Pattern : Exactly K Distinct Elements 

#include<bits/stdc++.h>
int atmost(vector<int> &arr, int n, int k)
{
    int l,r;
    l=r=0;
    unordered_map<int,int>mpp;
    int count=0;
    while(r<n)
    {
        mpp[arr[r]]++;
        while(mpp.size()>k)
        {
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0)
            {
                mpp.erase(arr[l]);
            }
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
}
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
  return atmost(arr,n,k) - atmost(arr,n,k-1);
}
//TIME COMPLEXITY= O(n + n) = O(N)
//SPACE COMPLEXITY=O(K)
