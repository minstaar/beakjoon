#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 16
using namespace std;

vector<int> adj[30010];
int parent[30010][MAX], depth[30010];

void makeTreebyDFS(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next] == -1){
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            makeTreebyDFS(next);
        }
    }
}

int Dist(int u, int v)
{
    int s = u, e = v;
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++){
        if(diff % 2) u = parent[u][i];
        diff /= 2;
    }

    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }
    return depth[s] + depth[e] - 2 * depth[u];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    makeTreebyDFS(1);
    for(int i=0; i<=MAX-2; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i+1] = parent[parent[j][i]][i];
        }
    }

    int M; cin >> M;
    int ans = 0;
    int from = 1;
    for(int i=0; i<M; i++){
        int to; cin >> to;
        ans += Dist(from, to);
        from = to;
    }

    cout << ans << '\n';

    return 0;
}