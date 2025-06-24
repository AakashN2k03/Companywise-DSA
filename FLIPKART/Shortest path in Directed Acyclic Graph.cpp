// GFG: Shortest path in Directed Acyclic Graph

// Pattern 4 - Dijkstra / Shortest Path

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adjls(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            adjls[u].push_back({v,wt});
        }
        
        vector<int>distance(V,1e9);
        distance[0]=0;
        set<pair<int,int>>st;
        st.insert({0,0}); // distance ,node
        
        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int dist=it.first;
            st.erase(it);
            
            for(auto & neighbour:adjls[node])
            {
                int adjnode=neighbour.first;
                int edge_weight=neighbour.second;
                
                if(dist+edge_weight < distance[adjnode])
                {
                    if(distance[adjnode]!=1e9)
                    {
                        st.erase({distance[adjnode],adjnode});
                    }
                    
                    distance[adjnode]=dist+edge_weight;
                    st.insert({distance[adjnode],adjnode});
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (distance[i] == 1e9) distance[i] = -1;
        }

        return distance;
    }
};

// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
