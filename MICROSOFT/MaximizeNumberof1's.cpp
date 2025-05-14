// GFG: Maximize Number of 1's

class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
       int l,r,n;
       l=0,r=0;
       n=arr.size()-1;
       int zeros=0;
       int maxi=INT_MIN;
       while(r<=n)
       {
           if(arr[r]==0)
           {
               zeros++;
           }
            while(zeros>k)
           {
               if(arr[l]==0)
               {
                 zeros--;   
               }
               l++;
           }
           maxi=max(maxi,(r-l+1));
           r++; 
       }
       return maxi; 
    }
};

//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(1)
