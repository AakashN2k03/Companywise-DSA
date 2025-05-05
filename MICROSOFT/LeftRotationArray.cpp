// CODE360: Rotate array
#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;  // Handle cases where k > n

    // Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k); // O(K)
    
    // Reverse the remaining elements
    reverse(arr.begin() + k, arr.end()); // O(N-K)
    
    // Reverse the entire array to achieve the rotation
    reverse(arr.begin(), arr.end());    // O(N)
    
    return arr;
}

//TIME COMPLEXITY:O(K)+O(N-K)+O(N) =O(2N)=O(N)
//SPACE COMPLEXITY:O(1)
