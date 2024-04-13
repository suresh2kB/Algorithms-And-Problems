class Solution {
public:
    void dfs(int u,vector<int> curr,vector<vector<int>> &ans,vector<vector<int>> graph)
    {
        curr.push_back(u);
        if(u==graph.size()-1)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int v : graph[u])
        {
            dfs(v,curr,ans,graph);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;

        vector<int> curr;
        dfs(0,curr,ans,graph);
        
        return ans;
    }
};
