// CODE360: Anagram Pairs

#include<bits/stdc++.h>
bool isAnagram(string str1, string str2)
{   // Check if lengths are different
    if(str1.length() != str2.length()) {
        return false;  
    }
    sort(str1.begin(),str1.end()); // O(N log N) 
    sort(str2.begin(),str2.end()); //O(N log N) 
    for(int i=0;i<str1.length();i++) // O(N)
    {
        if(str1[i]!=str2[i]) return false;
    }

return true;
}

// TIME COMPLEXITY:O(N log N) 
// SPACE COMPLEXITY:O(1)
  
