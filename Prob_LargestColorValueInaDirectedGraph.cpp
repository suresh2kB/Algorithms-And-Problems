class Solution {
public:
    vector<vector<int>> adj;
    unordered_map<int,vector<int>> mp;

    vector<int> dfs(int u,string &s,vector<int> &vis,int &ans)
    {
        vis[u] = 1;
        vector<int> H(26,0);

        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vector<int> curr = dfs(v,s,vis,ans);
                for(int i=0;i<curr.size();i++){
                    H[i]=max(H[i],curr[i]);
                }
            }
            else if(vis[v]==1)
            {
                ans = INT_MAX;
            }
            else{
                vector<int> curr = mp[v];
                for(int i=0;i<curr.size();i++){
                    H[i] = max(H[i],curr[i]);
                }
            }
        }
        H[s[u]-'a']++;
        for(int i=0;i<H.size();i++){
            ans = max(ans,H[i]);
        }
        vis[u] = 2;
        mp[u] = H;
        return mp[u];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                dfs(i,colors,vis,ans);
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};
