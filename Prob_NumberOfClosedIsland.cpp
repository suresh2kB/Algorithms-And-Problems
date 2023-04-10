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
