class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int djkastra(int n,int src)
    {
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        dist[src] = 0;
        st.insert({dist[src],src});

        while(!st.empty())
        {
            auto it = st.begin();
            int node = it->second;
            int nodeWeight  =it->first;
            st.erase(it);

            for(auto nbrPair : adj[node])
            {
                int nbr = nbrPair.first;
                int nbrWeight = nbrPair.second;

                if(nodeWeight+nbrWeight<dist[nbr])
                {
                    auto f = st.find({dist[nbr],nbr});
                    if(f!=st.end())
                    {
                        st.erase(f);
                    }
                    dist[nbr] = nodeWeight+nbrWeight;
                    st.insert({dist[nbr],nbr});
                }
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            ans = max(ans,dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adj.resize(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            u--;
            v--;
            adj[u].push_back({v,w});
        }
        int maxDelayTime = djkastra(n,k-1);

        return maxDelayTime==INT_MAX?-1:maxDelayTime;
    }
};
