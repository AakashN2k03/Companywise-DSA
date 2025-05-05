// CODE360:  Duplicate In Array
#include<bits/stdc++.h>
int findDuplicate(vector<int> &arr) 
{
    unordered_map<int,int>mpp;
    for(int num:arr)
    {
        mpp[num]++;
    }
    for(auto x:mpp)
    {
        if(x.second==2) return x.first;
    }
	
    return -1;
}
// Time complexity=O(n)+O(n)=O(n)
// Space complexity=O(n)



