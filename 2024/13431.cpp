#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N;
vector<pii> adj[100010];

struct CentroidTree{
    vector<int> sz, parent;
    vector<bool> visited;

    CentroidTree(int n): sz(n), visited(n), parent(n) {}

    int getSize(int prev, int cur){
        sz[cur] = 1;
        for(auto [next, cost]: adj[cur]){
            if(next != prev && !visited[next]){
                sz[cur] += getSize(cur, next);
            }
        }
        return sz[cur];
    }

    int getCent(int prev, int cur, int cnt){
        for(auto [next, cost]: adj[cur]){
            if(next != prev && !visited[next] && sz[next] * 2 > cnt){
                return getCent(cur, next, cnt);
            }
        }
        return cur;
    }

    void init(int prev, int cur){
        int cent = getCent(prev, cur, getSize(prev, cur));
        visited[cent] = true;
        parent[cent] = prev;
        for(auto [next, cost]: adj[cent]){
            if(!visited[next]) init(cent, next);
        }
    }
};

struct LCA{
    int parent[100010][20], depth[100010];
    ll dist[100010];

    void init()
    {
        queue<int> que;
        que.push(0);
        depth[0] = 1;
        while(!que.empty()){
            int cur = que.front(); que.pop();
            for(auto [next, cost]: adj[cur]){
                if(!depth[next]){
                    depth[next] = depth[cur] + 1;
                    parent[next][0] = cur;
                    dist[next] += dist[cur] + cost;
                    que.push(next);
                }
            }
        }
        for(int i=1; i<=19; i++){
            for(int j=0; j<N; j++){
                parent[j][i] = parent[parent[j][i-1]][i-1];
            }
        }
    }

    int getLca(int u, int v)
    {
        if(depth[u] < depth[v]) swap(u, v);
        for(int i=19; i>=0; i--){
            if(depth[u] - depth[v] >= (1 << i)) u = parent[u][i];
        }
        if(u == v) return u;
        for(int i=19; i>=0; i--){
            if(parent[u][i] ^ parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }

    ll getDist(int u, int v)
    {
        return dist[u] + dist[v] - 2 * dist[getLca(u, v)];
    }
};

CentroidTree CT(100010);
LCA lca;
bool color[100010];
int cnt[100010];
ll dp[100010], dp2[100010];

void update(int v)
{
    if(color[v]) return;
    color[v] = 1;
    cnt[v]++;
    int cur = CT.parent[v], prev = v;
    while(cur != -1){
        ll dist = lca.getDist(cur, v);
        cnt[cur]++;
        dp[cur] += dist;
        dp2[prev] += dist;
        prev = cur;
        cur = CT.parent[cur];
    }
}

ll query(int v)
{
    int cur = CT.parent[v], prev = v;
    ll ret = dp[v];
    while(cur != -1){
        ret += dp[cur] - dp2[prev];
        ll dist = lca.getDist(cur, v);
        ret += dist * (cnt[cur] - cnt[prev]);
        prev = cur;
        cur = CT.parent[cur];
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q; cin >> N >> Q;
    for(int i=0; i<N-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    CT.init(-1, 0);
    lca.init();

    while(Q--){
        int a, b; cin >> a >> b;
        if(a == 1) update(b);
        else{
            cout << query(b) << '\n';
        }
    }

    return 0;
}