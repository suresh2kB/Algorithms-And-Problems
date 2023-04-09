class Solution {
public:
    vector<vector<pair<int,int>>> adj;

    int djkastra(int u,int n,int range)
    {
        vector<int> dist(n,INT_MAX);
        dist[u] = 0;
        set<pair<int,int>> st;
        st.insert({dist[u],u});

        while(!st.empty())
        {
            auto top = st.begin();
            int u = top->second;
            int w = top->first;
            st.erase(top);

            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;

                if(w+weight<dist[v])
                {
                    dist[v] = w+weight;
                    st.insert({dist[v],v});
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(dist[i]<=range);
        }

        return cnt-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int range) {
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans=0;
        int cnt=INT_MAX;
        for(int i=0;i<n;i++){
            int count = djkastra(i,n,range);
            if(count<=cnt)
            {
                cnt = count;
                ans = i;
            }
        }

        return ans;
    }
};
