#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 20
#define ll long long
using namespace std;

typedef pair<int, int> pii;
vector<pii> adj[100010];
int parent[100010][MAX], depth[100010];
ll dist[100010][MAX];

void makeTree(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next.first] == -1){
            parent[next.first][0] = cur;
            depth[next.first] = depth[cur] + 1;
            dist[next.first][0] = next.second;
            makeTree(next.first);
        }
    }
}

pair<int, ll> LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    ll cost = 0;
    for(int i=0; diff; i++){
        if(diff % 2){
            cost += dist[u][i];
            u = parent[u][i];
        }
        diff /= 2;
    }

    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                cost += dist[u][i] + dist[v][i];
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        cost += dist[u][0] + dist[v][0];
        u = parent[u][0];
    }
    
    return {u, cost};
}

int FindNode(int u, int v, int k)
{
    int lca = LCA(u, v).first;
    int node;
    if(depth[u] - depth[lca] + 1 == k) return lca;
    else if(depth[u] - depth[lca] >= k){
        int farLeaf = k - 1;
        node = u;
        for(int i=0; farLeaf; i++){
            if(farLeaf % 2) node = parent[node][i];
            farLeaf /= 2;
        }
    }
    else{
        int farLeaf = (depth[u] + depth[v] - 2 * depth[lca]) - k + 1;
        node = v;
        for(int i=0; farLeaf; i++){
            if(farLeaf % 2) node = parent[node][i];
            farLeaf /= 2;
        }
    }
    
    return node;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    makeTree(1);

    for(int i=0; i<MAX-1; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i+1] = parent[parent[j][i]][i];
            dist[j][i+1] = dist[j][i] + dist[parent[j][i]][i];
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        if(a == 1){
            int u, v; cin >> u >> v;
            cout << LCA(u, v).second << '\n';
        }
        else{
            int u, v, k; cin >> u >> v >> k;
            cout << FindNode(u, v, k) << '\n';
        }
    }

    return 0;
}