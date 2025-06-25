// Code360: Path With Minimum Effort

// Pattern:  Dijkstra / Shortest Path
  
#include <bits/stdc++.h>
using namespace std;

int minimumTimeTakingPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[0][0] = 0;

    // {effort, {row, col}}
    set<pair<int, pair<int, int>>> st;
    st.insert({0, {0, 0}});

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};

    while (!st.empty())
    {
        auto it = *(st.begin());
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        st.erase(it);

        if (row == n - 1 && col == m - 1)
            return diff;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int effort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);

                if (effort < distance[nrow][ncol])
                {
                    distance[nrow][ncol] = effort;
                    st.insert({effort, {nrow, ncol}});
                }
            }
        }
    }

    return -1; // This line is unreachable if the graph is connected
}

// Time Complexity:	O(N × M × log(N × M))
// Space Complexity	O(N × M)
