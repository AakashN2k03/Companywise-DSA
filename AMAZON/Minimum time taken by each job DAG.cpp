// GFG: Minimum time taken by each job to be completed given by a Directed Acyclic Graph

// Pattern  - Topological Sort ( Kahn’s Algorithm + BFS)
  
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adjls(n + 1);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjls[u].push_back(v);
        }

        vector<int> indegree(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (auto it : adjls[i]) {
                indegree[it]++;
            }
        }

        queue<pair<int, int>> qu;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) qu.push({i, 1});
        }

        vector<int> ans(n + 1, 0);  // index represents task, value is time
        while (!qu.empty()) {
            int node = qu.front().first;
            int timer = qu.front().second;
            qu.pop();
            ans[node] = timer;
            for (auto it : adjls[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    qu.push({it, timer + 1});
                }
            }
        }

        // Remove the 0th index as nodes are 1-indexed
        vector<int> finalAns(ans.begin() + 1, ans.end());
        return finalAns;
    }
};
// Time Complexity:O(E+V);
// Space Complexity:O(E+V);
