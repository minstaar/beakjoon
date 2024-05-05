#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 20
using namespace std;

struct Path
{
    int min = 1e9;
    int max = -1;
};

vector<pair<int, int>> adj[100010];
int parent[100010][MAX], depth[100010];
Path dist[100010][MAX];

void makeTree(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next.first] == -1){
            parent[next.first][0] = cur;
            depth[next.first] = depth[cur] + 1;
            dist[next.first][0].min = next.second;
            dist[next.first][0].max = next.second;
            makeTree(next.first);
        }
    }
}

Path Query(int u, int v)
{
    Path ans;
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++){
        if(diff % 2){
            ans.min = min(ans.min, dist[u][i].min);
            ans.max = max(ans.max, dist[u][i].max);
            u = parent[u][i];
        }
        diff /= 2;
    }

    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                ans.min = min({ans.min, dist[u][i].min, dist[v][i].min});
                ans.max = max({ans.max, dist[u][i].max, dist[v][i].max});
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        ans.min = min({ans.min, dist[u][0].min, dist[v][0].min});
        ans.max = max({ans.max, dist[u][0].max, dist[v][0].max});
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

    for(int i=0; i<MAX-1; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i+1] = parent[parent[j][i]][i];
            dist[j][i+1].min = min(dist[j][i].min, dist[parent[j][i]][i].min);
            dist[j][i+1].max = max(dist[j][i].max, dist[parent[j][i]][i].max);
        }
    }

    int K; cin >> K;
    for(int i=0; i<K; i++){
        int u, v; cin >> u >> v;
        Path ans = Query(u, v);
        cout << ans.min << " " << ans.max << '\n';
    }
    return 0;
}