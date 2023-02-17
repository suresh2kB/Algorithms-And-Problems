#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const int N_Max = 2e5 + 7;
const ll mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<int> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<int, int> p){cout << p.F << " " << p.S << endl;}
void dbgpi(vector<pair<int, int>> v){for (auto x : v) dbgg(x);}
 
vector<int> adj[N_Max], parent;
bool visited[N_Max];
 
bool leaf(int Node, int par){
    for (int child : adj[Node])
        if (child != par)
            return false;
    return true;
}
 
void dfs(int Node, int par){
    parent[Node] = par;
    if (leaf(Node, par) == true)
        return;
    for (int child : adj[Node]){
        if (child != par)
            dfs(child, Node);
    }
}
 
void solve(){
    int N;
    cin >> N;
    parent.resize(N + 1);
    vector<int> v(N + 1);
    for (int i = 1; i < N; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    dfs(1, 0);
    if (v[1] != 1){
        cout << "No" << endl;
        return;
    }
    // for (int i = 1; i <= N; i++)
    //     cout << parent[i] << " ";
    // cout << endl;
    queue<int> q;
    q.push(1);
    int index = 2;
    while (index <= N){
        int Node = q.front();
        q.pop();
        // cout << Node << " ";
        for (int i = index; i <= index + adj[Node].size() - 1 - (Node == 1 ? 0 : 1); i++){
            if (parent[v[i]] != Node){
                cout << "No" << endl;
                return;
            }
            q.push(v[i]);
        }
        index += adj[Node].size() - (Node == 1 ? 0 : 1);
    }
    cout << "Yes" << endl;
}
 
int main(){
    FAST
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
