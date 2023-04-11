class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};
    int maxTimeToRot(int n,int m,vector<vector<int>> grid)
    {
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            auto it = q.front();
            int i = it.first;
            int j = it.second;
            q.pop();

            for(int k=0;k<4;k++){
                int x = i+X[k];
                int y = j+Y[k];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && 1+dist[i][j]<dist[x][y])
                {
                    dist[x][y] = dist[i][j]+1;
                    ans = max(ans,dist[x][y]);
                    q.push({x,y});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    ans = max(ans,dist[i][j]);
                }
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return maxTimeToRot(n,m,grid);
    }
};
