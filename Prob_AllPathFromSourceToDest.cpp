class Solution {
public:
    void dfs(int u,vector<int> vis,vector<int> curr,vector<vector<int>> &ans,vector<vector<int>> graph)
    {
        curr.push_back(u);
        if(u==graph.size()-1)
        {
            ans.push_back(curr);
        }
        vis[u] = 1;
        
        for(int v : graph[u])
        {
            if(!vis[v])
            {
                dfs(v,vis,curr,ans,graph);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<vector<int>> ans;

        vector<int> curr;
        dfs(0,vis,curr,ans,graph);

        return ans;
    }
};
