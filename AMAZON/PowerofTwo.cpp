// CODE360:  Power of Two

// Pattern: Clever Bit Tricks

bool isPowerOfTwo(int n)
{	
    return (n>0 & (n& n-1)==0)?true:false;
}
// Time Compelxity:O(1)
// Space Compelxity:O(1)
