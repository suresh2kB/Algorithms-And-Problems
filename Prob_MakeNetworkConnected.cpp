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
