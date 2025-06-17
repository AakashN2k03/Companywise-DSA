// LEETCODE: 210. Course Schedule II

// Pattern  - Topological Sort ( Kahn’s Algorithm + BFS)
  
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjls(numCourses);
        for(auto it:prerequisites)
        {   int u=it[0];
            int v=it[1];
            
            adjls[v].push_back(u);
        }

        vector<int>indegree(numCourses);
          for (int i = 0; i < numCourses; i++) {
            for (auto adjnode : adjls[i]) {
                indegree[adjnode]++;
            }
        }

        queue<int>qu;
        for(int i=0;i<numCourses;i++)
        {   if(indegree[i]==0)
            {
            qu.push(i);
             }
        }
        vector<int>ans;
       int counter=0;
        while(!qu.empty())
        {
            int node=qu.front();
            qu.pop();
            counter++;
            ans.push_back(node);
        
            for(auto adjnode:adjls[node])
            {  indegree[adjnode]--;
               if(indegree[adjnode]==0)
               { 
                qu.push(adjnode);
               }
            }

        }
        if(counter==numCourses) return ans;
        return {};
    }
};
// Time Complexity:O(V+E)
// Space Complexity:O(V+E)
