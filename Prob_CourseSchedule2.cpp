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
