// GFG:  L to R XOR 

class Solution {
  public:
    int xorr(int n)
    {
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n; // if(n%4==0) return n;
    }
    int findXOR(int l, int r) {
       
       return xorr(r)^xorr(l-1);
    }
};
// Time Complexity:O(1)
// Space Complexity:O(1)
