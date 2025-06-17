// LEETCODE: 207.Course Schedule

// Pattern  - Topological Sort ( Kahn’s Algorithm + BFS)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjls(numCourses);
        for(auto edge:prerequisites )
        {
            int u=edge[0];
            int v=edge[1];
            adjls[u].push_back(v);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adjls[i])
            {
                indegree[it]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
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

            for(auto it:adjls[node])
            {   indegree[it]--;
                if(indegree[it]==0)
                {
                    qu.push(it);
                }
            }
        }
        return counter==numCourses;
        
    }
};
// Time Complexity:O(V+E)
// Space Complexity:O(V+E)
