class Solution {
public:
    vector<int> X = {-1,1,0,0};
    vector<int> Y = {0,0,-1,1};
    vector<vector<int>> vis;

    void dfs(int i,int j,vector<vector<int>> &image,int color)
    {
        image[i][j] = -1;

        for(int k=0;k<4;k++){
            int x = i+X[k];
            int y = j+Y[k];

            if(x>=0 && y>=0 && x<image.size() && y<image[0].size() && image[x][y]==color)
            {
                dfs(x,y,image,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int n = image.size();
        int m = image[0].size();
        int initial = image[sr][sc];

        dfs(sr,sc,image,initial);

        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[i].size();j++){
                if(image[i][j]==-1)
                {
                    image[i][j] = color;
                }
            }
        }
        return image;
    }
};
