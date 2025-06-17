// CODE360: Longest Common Subsequence

 // Pattern  : Subsequence Based

#include <bits/stdc++.h> 
int LongestCommonSubsequence(int index1,int index2,string& str1,string& str2,vector<vector<int>>&dp)
{
  if(index1<0 || index2<0) return 0;
  if(dp[index1][index2]!=-1) return dp[index1][index2]; 
  if(str1[index1]==str2[index2])
  {
    return dp[index1][index2]=1+LongestCommonSubsequence(index1-1,index2-1,str1,str2,dp);
  }

  return dp[index1][index2]=max(LongestCommonSubsequence(index1,index2-1,str1,str2,dp),
  LongestCommonSubsequence(index1-1,index2,str1,str2,dp));
}
int getLengthOfLCS(string & str1, string & str2) {
  int n=str1.length();
  int m=str2.length();

  vector<vector<int>>dp(n,vector<int>(m,-1));
  return  LongestCommonSubsequence(n-1,m-1,str1,str2,dp);
}
// Time Complexity:(n*m);
// Time Complexity:(n*m);
