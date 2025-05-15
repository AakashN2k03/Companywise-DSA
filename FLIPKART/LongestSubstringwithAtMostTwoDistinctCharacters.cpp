// CODE 360: Longest Substring with At Most Two Distinct Characters

// PATTERN : Variable Size Window

int lengthOfLongestSubstring(string s) {
    int l,r,n;
    n=s.length();
    l=r=0;
    unordered_map<int,int>mpp;
    int maxlen=0;
    while(r<n)
    {
        mpp[s[r]]++;
        while(mpp.size()>2)
        {
            mpp[s[l]]--;
            if(mpp[s[l]]==0)
            {
                mpp.erase(s[l]);
            }
        l++;
        }
        maxlen=max(maxlen,(r-l+1));
        r++;
    }
    return maxlen;
}
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY: O(N)
