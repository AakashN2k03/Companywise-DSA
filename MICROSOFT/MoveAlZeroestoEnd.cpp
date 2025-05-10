// GFG: Move All Zeroes to End

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n=arr.size();
        int l,r;
        l=r=0;
        while(r<n)
        {
            if(arr[r]!=0)
            {
                swap(arr[l],arr[r]);
                l++;
            }
            r++;
        }
    }
};
// Time complexity:O(n)
// space complexity:O(1)
