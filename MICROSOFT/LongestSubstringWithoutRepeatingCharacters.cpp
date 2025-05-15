// CODE 360: Longest Substring Without Repeating Characters 

// PATTERN : Variable Size Window

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int l,r,n;
    n=input.length();
    l=r=0;
    unordered_map<int,int>mpp;
    int maxi=0;
    while(r<n)
    {
        mpp[input[r]]++;
        while(mpp[input[r]]>1)
        {
            mpp[input[l]]--;
            if(mpp[input[l]]==0)
            {
                mpp.erase(input[l]);
            }
            l++;
        }
        maxi=max(maxi,(r-l+1));
        r++;
    }
        return maxi;
}
//Time complexity:O(N)
//Space complexity:O(N)
