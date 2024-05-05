You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

 

Example 1:



Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Example 2:



Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
Example 3:



Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

    
class Solution {
public:

    int find(int u,vector<int> &parent)
    {
        if(parent[u]==-1)
        {
            return u;
        }

        return parent[u] = find(parent[u],parent);
    }

    void unionSet(int u,int v,vector<int> &parent,vector<int> &deg)
    {
        int s1 = find(u,parent);
        int s2 = find(v,parent);

        if(s1!=s2)
        {
            if(deg[s1]<deg[s2])
            {
                parent[s1] = s2;
            }
            else if(deg[s2]<deg[s1])
            {
                parent[s2] = s1;
            }
            else{
                deg[s1]++;
                parent[s2] = s1;
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    arr.push_back({i,j});
                }
            }
        }
        int sz = arr.size();
        vector<int> parent(sz,-1);
        vector<int> deg(sz,0);

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i].first==arr[j].first || arr[i].second==arr[j].second)
                {
                    unionSet(i,j,parent,deg);
                }
            }
        }

        int cnt = arr.size();
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1 && deg[i]==0)
            {
                cnt--;
            }
        }

        return cnt;
    }
};
