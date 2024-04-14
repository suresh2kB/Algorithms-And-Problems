You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 
Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.


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

    void unite(int u,int v,vector<int> &parent,vector<int> &deg)
    {
        int s1 = find(u,parent);
        int s2 = find(v,parent);

        if(deg[s1]<deg[s2])
        {
            parent[s1] = s2;
        }
        else if(deg[s2]<deg[s1])
        {
            parent[s2] = s1;
        }
        else
        {
            parent[s1] = s2;
            deg[s2]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        vector<int> parent(n,-1);
        vector<int> deg(n,0);
        int ans=0;

        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            int w = edges[i][0];

            if(find(u,parent)!=find(v,parent)){
                ans+=w;
                unite(u,v,parent,deg);
                // cout<<u<<" "<<v<<" "<<w<<endl;
            }
        }
        return ans;
    }
};
