// LEETCODE: 1976. Number of Ways to Arrive at Destination

// Pattern : Dijkstra / Shortest Path

#include <vector>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjls(n);
        for(auto road : roads) {
            adjls[road[0]].push_back({road[1], road[2]});
            adjls[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> distance(n, LLONG_MAX); // Use long long to prevent overflow
        vector<int> ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        int mod = 1e9 + 7;
        
        while(!pq.empty()) {
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // This check is important to avoid processing outdated entries
            // if(cost > distance[node]) continue;
            
            for(auto it : adjls[node]) {
                int adjnode = it.first;
                long long edge_weight = it.second; // Use long long here
                
                if(cost + edge_weight < distance[adjnode]) {
                    distance[adjnode] = cost + edge_weight;
                    pq.push({distance[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(cost + edge_weight == distance[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};

// Time Complexity:O(ElogN)
// Space Complexity: O(N+E)
