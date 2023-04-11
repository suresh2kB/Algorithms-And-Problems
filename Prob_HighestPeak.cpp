class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};

    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int x = i+X[k];
                int y = j+Y[k];

                if(x>=0 && y>=0 && x<n && y<m && dist[x][y]==INT_MAX)
                {
                    dist[x][y] = dist[i][j]+1;
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};
