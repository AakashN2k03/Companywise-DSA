// LEETCODE: 207.Course Schedule

// Pattern  - Topological Sort ( Kahn’s Algorithm + BFS)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

       int counter=0;
        while(!qu.empty())
        {
            int node=qu.front();
            qu.pop();
            counter++;
        
            for(auto adjnode:adjls[node])
            {  indegree[adjnode]--;
               if(indegree[adjnode]==0)
               { 
                qu.push(adjnode);
               }
            }

        }
       return numCourses==counter;
        
    }
};
// Time Complexity:O(V+E)
// Space Complexity:O(V+E)
