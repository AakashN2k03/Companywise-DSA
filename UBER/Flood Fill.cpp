// LEETCODE: 733. Flood Fill

// Pattern:DFS Traversal and BFS

//BFS
class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int intial_color,int color)
    {
        ans[row][col]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int n=ans.size();
        int m=ans[0].size();

        queue<pair<int,int>>qu;
        qu.push({row,col});

        while(!qu.empty())
        {   int row=qu.front().first;
            int col=qu.front().second;
            qu.pop();
            for(int i=0;i<4;i++)
            {
            int neighbour_row=row+drow[i];
            int neighbour_col=col+dcol[i];

            if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m 
            && ans[neighbour_row][neighbour_col]!=color && image[neighbour_row][neighbour_col]==intial_color )
            {   ans[neighbour_row][neighbour_col]=color;
                qu.push({neighbour_row,neighbour_col});
            }
            
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

       vector<vector<int>>ans=image;
       int initial_color=image[sr][sc];
       bfs(sr,sc,ans,image,initial_color,color);
       return ans; 
    }
};
// Time Complexity:O(M*N)
// Space Complexity:O(M*N)


// DFS
class Solution {
public:
void dfs(int row,int col,int drow[], int dcol[],vector<vector<int>>& image,vector<vector<int>>& ans,int initial_color,int color)
{int n=image.size();
int m=image[0].size();

ans[row][col]=color;
for(int i=0;i<4;i++) // four directions
{
int neighbour_row=row+drow[i];
int neighbour_col=col+dcol[i];

if(neighbour_row>=0 && neighbour_row<n && neighbour_col>=0 && neighbour_col<m &&
image[neighbour_row][neighbour_col]==initial_color && ans[neighbour_row][neighbour_col]!=color)
{
dfs(neighbour_row,neighbour_col,drow,dcol,image,ans,initial_color,color);

}

}
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
int initial_color=image[sr][sc];
vector<vector<int>> ans=image;
int drow[]={-1,0,1,0};
int dcol[]={0,1,0,-1};

dfs(sr,sc,drow,dcol,image,ans,initial_color,color);
return ans;

}
};

// Time Complexity:O(M*N)
// Space Complexity:O(M*N)
