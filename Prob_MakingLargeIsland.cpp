class Solution {
public:
    vector<vector<int>> dist,vis;
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};

    void dfs(int i,int j,int color,vector<pair<int,int>> &arr,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || vis[i][j] || grid[i][j]==0){
            return;
        }
        vis[i][j] = 1;
        arr.push_back({i,j});
        grid[i][j] = color;

        dfs(i-1,j,color,arr,grid);dfs(i+1,j,color,arr,grid);
        dfs(i,j-1,color,arr,grid);dfs(i,j+1,color,arr,grid);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dist.resize(n,vector<int>(m,0));
        vis.resize(n,vector<int>(m,0));

        int color=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])
                {
                    color++;
                    
                    vector<pair<int,int>> arr;
                    dfs(i,j,color,arr,grid);
                    int count=arr.size();
                    for(int k=0;k<arr.size();k++){
                        dist[arr[k].first][arr[k].second] = count;
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                unordered_map<int,int> mp;
                for(int k=0;k<4;k++){
                    int x = i+X[k];
                    int y = j+Y[k];
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[x].size())
                    {
                        mp[grid[x][y]] = dist[x][y];
                    }
                }
                int curr=0;
                for(auto it:mp)
                {
                    curr+=it.second;
                }
                if(vis[i][j]==0 || curr==0){
                    curr++;
                }
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};
