Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

Example 1:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:



Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

Constraints:

1 <= n <= 105
1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
edges[i].length == 3
1 <= typei <= 3
1 <= ui < vi <= n
All tuples (typei, ui, vi) are distinct.


class Solution {
public:
    int find(int u,vector<int> parent)
    {
        if(parent[u]==-1){
            return u;
        }

        return parent[u] = find(parent[u],parent);
    }

    void unite(int u,int v,vector<int> &parent,vector<int> deg)
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
        else{
            parent[s1] = s2;
            deg[s2]++;
        }
    }

    void solve(int &ans,vector<vector<int>> &edges,int type,vector<int> &parent,vector<int> &deg)
    {
        for(int i=0;i<edges.size();i++){
            int t = edges[i][0];
            if(t==type)
            {
                int u = edges[i][1];
                int v = edges[i][2];
                u--;
                v--;

                if(find(u,parent)!=find(v,parent))
                {
                    ans++;
                    unite(u,v,parent,deg);
                }
            }
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent1(n,-1),parent2(n,-1);
        vector<int> deg1(n,0),deg2(n,0);
        int ans=0;
        // sort(edges.begin(),edges.end());

        solve(ans,edges,3,parent1,deg1);

        for(int i=0;i<n;i++){
            parent2[i] = parent1[i];
            deg2[i] = deg1[i];
        }

        solve(ans,edges,1,parent1,deg1);
        solve(ans,edges,2,parent2,deg2);

        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(parent1[i]==-1){
                cnt1++;
            }
            if(parent2[i]==-1){
                cnt2++;
            }
            if(cnt1>1 || cnt2>1){
                return -1;
            }
        }

        return edges.size()-ans;
    }
};
