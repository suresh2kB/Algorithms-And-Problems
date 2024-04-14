There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.


class Solution {
public:
    vector<vector<int>> adj;

    bool dfs(int u,vector<int> &vis)
    {
        vis[u] = 1;

        for(int v : adj[u])
        {
            if(!vis[v])
            {
                bool nbrFoundCycle = dfs(v,vis);
                if(nbrFoundCycle){
                    return true;
                }
            }
            else if(vis[v]==1)
            {
                return true;
            }
        }
        vis[u] = 2;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        adj.resize(n);
        vector<int> indeg(n);
        for(int i=0;i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
            indeg[arr[i][0]]++;
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                bool foundCycle = dfs(i,vis);
                if(foundCycle){
                    return {};
                }
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> brr;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            brr.push_back(node);

            for(int nbr : adj[node])
            {
                indeg[nbr]--;
                if(indeg[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        return brr;
    }
};
