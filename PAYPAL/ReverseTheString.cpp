// CODE 360: Reverse the String

//SOLVE THIS by  O(1) space complexity
#include <bits/stdc++.h> 
string reverseString(string str)
{
	 int left,right;
	 left=0;
	 right=str.length()-1;

	 while(left<=right)
	 {
		 swap(str[left],str[right]);
		 left++;
		 right--;
	 }
	 return str;
}

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
