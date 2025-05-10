// CODE 360: Next Greater Element II

#include<bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int>& a) {
     int n=a.size();
     stack<int>st;
     vector<int>ans(n,-1);

     for(int i=2*n-1;i>=0;i--) // WHY 2*N-1 SINCE IT'S A CIRCULAR ARR 
    //  EG:[1,2,1] THEN IT BECOMES  [1,2,1,1,2,1]
     {
         while(!st.empty() && st.top()<=a[i%n])
         {
             st.pop();
         }
         
         if(i<n)
         {
             if(!st.empty())
             {
                 ans[i]=st.top();
             }
         }
         st.push(a[i%n]);
     }
     return ans;
}
// TIME COMPLEXITY:O(2N)=O(N);
// SPACE COMPLEXITY:O(N)
