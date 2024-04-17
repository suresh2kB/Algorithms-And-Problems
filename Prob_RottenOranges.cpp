You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

    
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
