// LEETCODE: 1. Two Sum 
// NEED TO RETURN INDEX

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

         unordered_map<int,int>map;
         int complement;
         for(int i=0;i<nums.size();i++)
         {      complement=target-nums[i];
                 if(map.find(complement)!=map.end())
                 {
                    return {map[complement],i};
                 }
                 map[nums[i]]=i;
                       
         }
        return {};
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

CODE 360:  Two Sum
// NEED TI RETURN ALL PAIRS OF VALUES (arr[i]) WHICH IS EQUAL TO TARGET

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int>& arr, int target, int n) {
    vector<pair<int, int>> ans;
    unordered_map<int, int> mpp;

    for (int num : arr) {
        int complement = target - num;
        if (mpp[complement] > 0) {
            ans.push_back({complement, num});
            mpp[complement]--;
        } else {
            mpp[num]++;
        }
    }

    if (ans.empty()) {
        ans.push_back({-1, -1});
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
