class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};
    unordered_map<int,vector<int>> mp;
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>> vis(n,vector<int>(m,0));
        mp[1] = {1,1,1,0};
        mp[2] = {1,1,0,1};
        mp[3] = {1,0,1,1};
        mp[4] = {0,1,1,1};

        deque<pair<int,int>> dq;
        dq.push_back({0,0});
        dist[0][0] = 0;

        while(!dq.empty())
        {
            int i = dq.front().first;
            int j = dq.front().second;
            dq.pop_front();
            vis[i][j] = 1;

            vector<int> extra = mp[grid[i][j]];
            for(int k=0;k<4;k++)
            {
                int x = i+X[k];
                int y = j+Y[k];
                int add = extra[k];
                if(x>=0 && y>=0 && x<n && y<m && dist[i][j]+add<dist[x][y])
                {
                    if(add==0)
                    {
                        dist[x][y] = dist[i][j];
                        dq.push_front({x,y});
                    }
                    else{
                        dist[x][y] = dist[i][j]+1;
                        dq.push_back({x,y});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
