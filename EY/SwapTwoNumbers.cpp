// CODE360:  Swap Two Numbers
void swapNumber(int &a, int &b) {
	a=a^b; //a =a+b
	b=a^b; //b =a-b
	a=a^b; //a = a-b
}
// Time Complexity: O(1)
// Space Complexity: O(1)
  
