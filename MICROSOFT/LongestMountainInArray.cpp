LEETCODE: Longest Mountain in Array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        if(arr.size()<3) return maxi;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int l=i;
                int r=i;

                while(l>0 && arr[l]>arr[l-1]) l--;
                while(r<n-1 && arr[r]>arr[r+1]) r++;

                maxi=max(maxi,(r-l+1));
            }
        }
        return maxi;
        
    }
};
// Time complexity:O(n)
// Space complexity:O(1)
