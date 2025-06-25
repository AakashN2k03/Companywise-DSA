// LEETCODE: 1091. Shortest Path in Binary Matrix

// Pattern 4 - Dijkstra / Shortest Path

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    // Step 1: Check for blocked start/end
    if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
        return -1;

    // ✅ Step 2: Handle 1x1 case (start == end) eg grid[[0]]
    if(n == 1) return 1;

    vector<vector<int>> distance(n, vector<int>(n, 1e9));
    distance[0][0] = 1;

    queue<pair<int, pair<int, int>>> qu;
    qu.push({1, {0, 0}});

    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    while(!qu.empty()) {
        int dist = qu.front().first;
        int row = qu.front().second.first;
        int col = qu.front().second.second;
        qu.pop();
        
        // if(row == n-1 && col == n-1) return dist  ;// can use here too

        for(int i = 0; i < 8; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && 
               grid[nrow][ncol] == 0 && dist + 1 < distance[nrow][ncol]) {

                if(nrow == n-1 && ncol == n-1) return dist + 1;

                distance[nrow][ncol] = dist + 1;
                qu.push({dist + 1, {nrow, ncol}});
            }
        }
    }

    return -1;
}
};

// ⏱️ Time Complexity:O(N^2)
// 🧠 Space Complexity:O(N^2)
