class Solution {
public:
    vector<vector<int>> adj;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vector<int> deg(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        int rem = n;
        for(int i=0;i<n;i++){
            if(deg[i]<=1)
            {
                q.push(i);
                vis[i] = 1;
            }
        }

        while(rem>2)
        {
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
                int u = q.front();
                q.pop();
                rem--;

                for(int v : adj[u])
                {
                    deg[v]--;
                    if(deg[v]==1)
                    {
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
