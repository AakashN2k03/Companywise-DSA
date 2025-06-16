// CODE360:  Walls And Gates

// Pattern - BFS

#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    vector<vector<int>>ans=a;
    queue<pair<int,int>>qu; // row,col;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ans[i][j]==0)
            {
                qu.push({i,j});
            }
        }
    }

    int drow[]={-1,0,1,0};
    int dcol[]={0,-1,0,1};

    while(!qu.empty())
    {
        int row=qu.front().first;
        int col=qu.front().second;
        qu.pop();

        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==INT_MAX)
            {
                ans[nrow][ncol]=ans[row][col] +1;
                qu.push({nrow,ncol});
            }

        }

    }
    return ans;
}
// Time Complexity:O(N * M)
// Space Complexity:O(N * M)

