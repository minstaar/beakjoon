#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 18
#define ll long long
using namespace std;

typedef pair<int, int> pii;
int parent[40010][MAX], depth[40010];
ll dist[40010][MAX];
vector<pii> adj[40010];

void makeTree(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next.first] == -1){
            depth[next.first] = depth[cur] + 1;
            parent[next.first][0] = cur;
            dist[next.first][0] = next.second;
            makeTree(next.first);
        }
    }
}

ll Dist(int u, int v)
{
    ll ans = 0;
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++){
        if(diff % 2){
            ans += dist[u][i];
            u = parent[u][i];
        }
        diff /= 2;
    }
    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                ans += dist[u][i] + dist[v][i];
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        ans += dist[u][0] + dist[v][0];
        u = parent[u][0];
    }
    return ans;
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
    for(int i=0; i<=MAX-2; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i+1] = parent[parent[j][i]][i];
            dist[j][i+1] = dist[j][i] + dist[parent[j][i]][i];
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        cout << Dist(u, v) << '\n';
    }

    return 0;
}