// CODE360: Saving Money

// Pattern - Dijkstra / Shortest Path

// Note:
// 1.Saving Money is same as Cheapest flight at K stops problem
// 2. Use chatgpt for asking why the time and space complexity

int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    vector<vector<pair<int, int>>> adjls(n);  // use 'n' not 'size' (node count)

    for (auto train : trains) {
        int u = train[0];
        int v = train[1];
        int wt = train[2];
        adjls[u].push_back({v, wt});
    }

    vector<int> distance(n, 1e9);
    distance[source] = 0;

    queue<pair<int, pair<int, int>>> qu; // Stops , Node , Cost
    qu.push({0, {source, 0}});

    while (!qu.empty()) {
        int Stops = qu.front().first;
        int Node = qu.front().second.first;
        int Cost = qu.front().second.second;
        qu.pop();

        if (Stops > K) continue;

        for (auto& neighbour : adjls[Node]) {
            int adjnode = neighbour.first;
            int edge_weight = neighbour.second;

            if (Cost + edge_weight < distance[adjnode]) {
                distance[adjnode] = Cost + edge_weight;
                qu.push({Stops + 1, {adjnode, distance[adjnode]}});
            }
        }
    }

    if (distance[destination] == 1e9) return -1;
    return distance[destination];
}
//  Time Complexity:O(K * E)
//  Space Complexity:O(V*K + E)
