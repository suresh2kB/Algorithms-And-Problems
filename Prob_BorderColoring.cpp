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
