// GFG: Set kth bit

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return n|(1<<k);
    }
};
//  Time Complexity: O(1)
//  Space Complexity: O(1)
