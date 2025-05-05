// LEETCODE: 189. Rotate Array 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end()); //O(N)
        reverse(nums.begin(),nums.begin()+k); //O(K)
        reverse(nums.begin()+k,nums.end()); //O(N-K)
    }
};
//TIME COMPLEXITY:O(K)+O(N-K)+O(N) =O(2N)=O(N)
//SPACE COMPLEXITY:O(1)
