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
