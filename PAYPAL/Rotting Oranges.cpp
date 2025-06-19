// LEETCODE: 994. Rotting Oranges

// Pattern - BFS
  
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qu; // ROW , COL, TIME   
        int fresh_orange_count=0;
       for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                qu.push({{i,j},0});
                vis[i][j]=2;
            }
            else if(grid[i][j]==1){
                vis[i][j]=1;
                fresh_orange_count++;
            }
        
        }
    }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int time=0;
        int count=0;
        while(!qu.empty())
        {
            int row=qu.front().first.first;   // ROW
            int col=qu.front().first.second; // COL
            int t=qu.front().second;          // TIME
            time=max(time,t);
            qu.pop();

            for(int i=0;i<4;i++)
            {
                int neighbour_row=row+drow[i];
                int neighbour_col=col+dcol[i];

                if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m && vis[neighbour_row][neighbour_col]!=2 && grid[neighbour_row][neighbour_col]==1)
                {
                    qu.push({{neighbour_row,neighbour_col},t+1});
                    vis[neighbour_row][neighbour_col]=2;
                    count++;
                }

            }
        }
        if(fresh_orange_count!=count) return -1;
        return time;

        
    }
};
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
