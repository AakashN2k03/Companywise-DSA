// LEETCODE: 31. Next Permutation

// Pattern : Permutations

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // STEP 1: Find the dip in the array
        // i.e., find the first index from the right such that nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If the entire array is in descending order, reverse it to get the smallest permutation
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // STEP 2: Find the element just greater than nums[index] from the right side
        // This is the smallest element larger than nums[index] to make the next permutation just larger
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // STEP 3: Reverse the suffix starting right after the index to get the next lexicographically smallest arrangement
        reverse(nums.begin() + index + 1, nums.end());
    }
};
// Time Complexity=O(3N) = O(N)
// Space Complexity=O(3N) = O(1)



// ALTERNATIVE APPROACH

 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        next_permutation(nums.begin(),nums.end());
    }
};
        
