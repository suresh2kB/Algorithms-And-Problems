You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 
Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.


class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};
    vector<vector<int>> dist;

    void dfs(int i,int j,queue<pair<int,int>> &q,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)
        {
            return;
        }
        grid[i][j] = 0;
        dist[i][j] = 0;
        q.push({i,j});

        dfs(i-1,j,q,grid);dfs(i+1,j,q,grid);
        dfs(i,j-1,q,grid);dfs(i,j+1,q,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        dist.resize(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++){
            bool find = false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    find = true;
                    dfs(i,j,q,grid);
                    break;
                }
            }
            if(find){
                break;
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

                if(x>=0 && y>=0 && x<n && y<m)
                {
                    if(grid[x][y]==1)
                    {
                        return dist[i][j];
                    }
                    else if(grid[x][y]==0 && 1+dist[i][j]<dist[x][y])
                    {
                        dist[x][y] = dist[i][j]+1;
                        q.push({x,y});

                    }
                }
            }
        }
        return -1;
    }
};
