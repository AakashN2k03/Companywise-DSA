// GFG:  Addition of Two Numbers

class Solution {
  public:
    int addition(int a, int b) {
        // code here
        while(b!=0)
        {
            int sum=a^b;
            int carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return a;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)
