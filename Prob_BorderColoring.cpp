You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.

Two squares are called adjacent if they are next to each other in any of the 4 directions.

Two squares belong to the same connected component if they have the same color and they are adjacent.

The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.

Return the final grid.

 

Example 1:

Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j], color <= 1000
0 <= row < m
0 <= col < n
    
class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};

    void dfs(int i,int j,int color,vector<vector<int>> &grid)
    {
        // cout<<grid[i][j]<<" ";
        int cnt=0;
        for(int k=0;k<4;k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                cnt++;
            }
            else if(x>=0 && y>=0 && x<grid.size() && y<grid[x].size() && grid[x][y]!=color && grid[x][y]!=0 && grid[x][y]!=-1)
            {
                cnt++;
            }
        }
        // cout<<i<<" "<<j<<" "<<cnt<<endl;
        int num = grid[i][j];
        if(cnt>0){
            grid[i][j] = 0;
        }
        else{
            grid[i][j] = -1;
        }

        for(int k=0;k<4;k++){
            int x = i+X[k];
            int y = j+Y[k];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[x].size() && grid[x][y]==color)
            {
                dfs(x,y,color,grid);
            }
        }

    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        
        int prev = grid[row][col];
        
        dfs(row,col,grid[row][col],grid);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    grid[i][j] = color;
                }
                else if(grid[i][j]==-1){
                    grid[i][j] = prev;
                }
            }
        }
        
        return grid;
    }
};
