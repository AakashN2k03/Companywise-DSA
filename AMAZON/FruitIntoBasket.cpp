// GFG: Find length of the longest subarray containing atmost two distinct integers (FRUIT INTO BASKET)

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        int l,r;
        l=r=0;
        unordered_map<int,int>mpp;
        while(r<n)
        {
            mpp[arr[r]]++;
            
            while(mpp.size()>2)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
              
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
    }
};
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)
