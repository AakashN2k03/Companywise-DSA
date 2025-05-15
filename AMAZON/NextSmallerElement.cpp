// CODE 360: Next Smaller Element 

// PATTERN : Monotonic Stack  (Next Greater / Smaller Element)

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n,-1);
    stack<int>st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(arr[i]);
    }
    return ans;
}
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
