Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
    
class Solution {
public:
    void dfs(int i,int j,bool &find,vector<vector<int>> &grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j==grid[i].size() || grid[i][j]==1)
        {
            return;
        }
        if(i==0 || i==grid.size()-1 || j==0 || j==grid[i].size()-1)
        {
            find = true;
        }
        grid[i][j] = 1;

        dfs(i-1,j,find,grid);
        dfs(i+1,j,find,grid);
        dfs(i,j-1,find,grid);
        dfs(i,j+1,find,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                {
                    bool find = false;
                    dfs(i,j,find,grid);
                    if(!find)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
