// CODE 360:  Min Stack 

// Pattern : Stack Simulation (Custom Logic)

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<pair<int,int>>st; // actual data, min data
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.

		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{	int mini;
			if(st.empty())
			{
                mini=num;
			}
			else{
				mini=min({num,st.top().second});
			}
			st.push({num,mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;
			int popped_element=st.top().first;
			st.pop();
			return popped_element;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
		if(st.empty()) return -1;
		return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			return st.top().second;
		}
};
// Time Complexity :O(1)
// Space Complexity :O(N)
