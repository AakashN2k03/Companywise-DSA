// LEETCODE: 268. Missing Number 

// NOTE:missing = xor(0 to n) ^ xor(all elements in array)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        int xor2=0;
        for(int i=0;i<=n;i++)
        {
            xor1^=i;
        }
        for(int num:nums)
        {
            xor2^=num;
        }
        return xor1^xor2;
    }
};
// Time Complexity: O(n)
//  Space Complexity: O(1)

// ALTERNATIVE WAY

// NOTE:missing = total_sum - actual_sum

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int actual_sum=0;
        int n=arr.size()+1;
        for(int num:arr)
        {
            actual_sum+=num;
        }
        int total_sum=(n*(n+1))/2;
        return total_sum-actual_sum;
    }
};
