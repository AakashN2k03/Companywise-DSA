// CODE360: Next Greater Element

#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n){
    // unordered_map<int,int>mpp;
    vector<int>ans;
    stack<int>st;
    //it is better to travel from backwards to find next greatest element
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(arr[i]);

    }
     reverse(ans.begin(), ans.end()); // reverse to maintain original order
    return ans;
}
//Time Complexity:O(n)+o(n)+o(n) (for)(while)(reverse)=>o(n)
// o(n)The while loop runs only when elements are popped from the stack, but since each element is pushed once and popped at most once, the total number of operations is proportional to n.
// Space Complexity: O(n)
