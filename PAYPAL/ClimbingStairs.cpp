// CODE 360:  Count Ways To Reach The N-th Stairs
#include <bits/stdc++.h>
using namespace std;

long long count_steps(int n, vector<long long>& dp) {
    int mod=1e9+7;
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (count_steps(n - 1, dp) + count_steps(n - 2, dp)) % mod;
}

int countDistinctWays(int n) {
    vector<long long> dp(n + 1, -1);
    return count_steps(n, dp);
}

// LEETCODE:70. Climbing Stairs 
class Solution {
public:
   int count_steps(int n,vector<int>&dp)
   { 
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    
    return dp[n]=(count_steps(n-1,dp)+count_steps(n-2,dp));
   }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        return count_steps(n,dp);
    }
};
TIME COMPELXITY: O(N)
SPACE COMPLEXITY: O(N)+O(N) -> STACK SPACE IS INVOLVED
