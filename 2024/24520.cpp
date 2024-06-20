#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 18;

int N, K;
vector<pii> adj[100010];
int parent[100010][MAX], depth[100010];
ll dist[100010][MAX];

void build()
{
    queue<int> que;
    que.push(1);
    depth[1] = 1;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto [next, cost]: adj[cur]){
            if(!depth[next]){
                depth[next] = depth[cur] + 1;
                parent[next][0] = cur;
                dist[next][0] = cost;
                que.push(next);
            }
        }
    }
    for(int i=1; i<MAX; i++){
        for(int j=1; j<=N; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
            dist[j][i] = dist[parent[j][i-1]][i-1] + dist[j][i-1];
        }
    }
}

int get_lca(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=MAX-1; i>=0; i--){
        if(depth[u] - depth[v] >= (1 << i)) u = parent[u][i];
    }
    if(u == v) return u;
    for(int i=MAX-1; i>=0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N-1; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    build();
    while(K--){
        int u, v; cin >> u >> v;
        int l = get_lca(u, v);
        ll dist1 = 0, dist2 = 0;
        int t = u;
        for(int i=MAX-1; i>=0; i--){
            if(depth[t] - depth[l] >= (1 << i)){
                dist1 += dist[t][i];
                t = parent[t][i];
            }
        }
        t = v;
        for(int i=MAX-1; i>=0; i--){
            if(depth[t] - depth[l] >= (1 << i)){
                dist2 += dist[t][i];
                t = parent[t][i];
            }
        }

        if((ll)abs(dist1 - dist2) % 2){
            cout << -1 << '\n';
            continue;
        }
        if(dist1 == dist2){
            cout << l << '\n';
            continue;
        }

        if(dist1 < dist2){
            swap(dist1, dist2);
            swap(u, v);
        }

        ll w = (dist1 - dist2) / 2;
        ll value = dist1 - w;
        int res = u;
        for(int i=MAX-1; i>=0; i--){
            if(dist[res][i] <= value){
                value -= dist[res][i];
                res = parent[res][i];
            }
        }
        if(value == 0) cout << res << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}