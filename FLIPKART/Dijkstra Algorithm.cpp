// GFG: Dijkstra Algorithm

// Pattern - Dijkstra / Shortest Path

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Since the graph is undirected
        }

        // Step 2: Use set to store {distance, node}
        set<pair<int, int>> st;
        vector<int> distance(V, 1e9);
        distance[src] = 0;
        st.insert({0, src});

        // Step 3: Dijkstra's Algorithm
        while (!st.empty()) {
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            st.erase(it);

            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dist + edgeWeight < distance[adjNode]) {
                    // Remove old entry if exists
                    if (distance[adjNode] != 1e9) {
                        st.erase({distance[adjNode], adjNode});
                    }
                    distance[adjNode] = dist + edgeWeight;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }
};
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
