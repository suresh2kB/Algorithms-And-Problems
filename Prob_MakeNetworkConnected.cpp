There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

    
class Solution {
public:
    vector<vector<int>> adj;

    void dfs(int u,vector<int> &vis)
    {
        vis[u] = 1;

        for(int v : adj[u])
        {
            if(!vis[v]){
                dfs(v,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total_cables = connections.size();
        adj.resize(n);
        for(int i=0;i<total_cables;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        if(total_cables<n-1)
        {
            return -1;
        }


        int cnt=0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis);
            }
        }

        return cnt-1;
    }
};
