#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100010];
const int MAX = 18;
int parent[100010][MAX], depth[100010];

void dfs(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next] == 0){
            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;
            dfs(next);
        }
    }
}

int getLCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=MAX-1; i>=0; i--){
        if(depth[u] - depth[v] >= (1 << i)) u = parent[u][i];
    }
    if(u == v) return u;
    for(int i=MAX-1; i>=0; i--){
        if(parent[u][i] ^ parent[v][i]){
            u = parent[u][i], v = parent[v][i];
        }
    }
    return parent[u][0];
}

int getDist(int u, int v)
{
    int lca = getLCA(u, v);
    int ret = 0;
    for(int i=MAX-1; i>=0; i--){
        if(depth[u] - depth[lca] >= (1 << i)){
            ret += (1 << i);
            u = parent[u][i];
        }
    }
    for(int i=MAX-1; i>=0; i--){
        if(depth[v] - depth[lca] >= (1 << i)){
            ret += (1 << i);
            v = parent[v][i];
        }
    }
    return ret;
}

int solve(int a, int b, int c)
{

    int dist = getDist(a, b);
    int m = depth[a] > depth[b] ? a : b;
    if(dist % 2 == 0){
        dist >>= 1;
        for(int i=MAX-1; i>=0; i--){
            if(dist >= (1 << i)){
                dist -= (1 << i);
                m = parent[m][i];
            }
        }
        if(getDist(a, m) == getDist(c, m)) return m; 
    }

    dist = getDist(a, c);
    m = depth[a] > depth[c] ? a : c;
    if(dist % 2 == 0){
        dist >>= 1;
        for(int i=MAX-1; i>=0; i--){
            if(dist >= (1 << i)){
                dist -= (1 << i);
                m = parent[m][i];
            }
        }
        if(getDist(a, m) == getDist(b, m)) return m; 
    }

    dist = getDist(b, c);
    m = depth[b] > depth[c] ? b : c;
    if(dist % 2 == 0){
        dist >>= 1;
        for(int i=MAX-1; i>=0; i--){
            if(dist >= (1 << i)){
                dist -= (1 << i);
                m = parent[m][i];
            }
        }
        if(getDist(b, m) == getDist(a, m)) return m; 
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);
    for(int i=1; i<MAX; i++){
        for(int j=1; j<=N; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }

    return 0;
}