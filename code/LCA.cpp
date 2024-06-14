#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;
struct Data{
    int min = INF;
    int max = -INF;
    ll sum = 0;
};

struct LCA{
    vector<vector<pii>> adj;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<Data>> dist;
    int n, log;

    void init(int _n){
        n = _n;
        adj = vector<vector<pii>>(n+1);
        for(; (1<<log)<=n; log++);
        log++;
        parent = vector<vector<int>>(n+1, vector<int>(log, -1));
        dist = vector<vector<Data>>(n+1, vector<Data>(log));
        depth = vector<int>(n+1, -1);
    }

    void addEdge(int u, int v, int c){
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void dfs(int cur){
        for(auto [next, cost]: adj[cur]){
            if(depth[next] == -1){
                depth[next] = depth[cur] + 1;
                parent[next][0] = cur;
                dist[next][0] = {cost, cost, cost};
                dfs(next);
            }
        }
    }

    void setParent(){
        depth[1] = 0;
        dfs(1);
        for(int i=0; i<=log-2; i++){
            for(int j=2; j<=n; j++){
                if(parent[j][i] != -1){
                    parent[j][i+1] = parent[parent[j][i]][i];
                    dist[j][i+1].min = min(dist[parent[j][i]][i].min, dist[j][i].min);
                    dist[j][i+1].max = max(dist[parent[j][i]][i].max, dist[j][i].max);
                    dist[j][i+1].sum = dist[parent[j][i]][i].sum + dist[j][i].sum;
                }
            }
        }
    }

    int get_lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=0; diff; i++){
            if(diff % 2) u = parent[u][i];
            diff /= 2;
        }
        if(u != v){
            for(int i=log-1; i>=0; i--){
                if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            u = parent[u][0];
        }
        return u;
    }

    Data get_dist(int u, int v){
        Data res;
        int a = get_lca(u, v);
        int diff = depth[u] - depth[a];
        for(int i=0; diff; i++){
            if(diff % 2){
                res.sum += dist[u][i].sum;
                res.min = min(res.min, dist[u][i].min);
                res.max = max(res.max, dist[u][i].max);
                u = parent[u][i];
            }
            diff /= 2;
        }
        diff = depth[v] - depth[a];
        for(int i=0; diff; i++){
            if(diff % 2){
                res.sum += dist[u][i].sum;
                res.min = min(res.min, dist[u][i].min);
                res.max = max(res.max, dist[u][i].max);
                u = parent[u][i];
            }
            diff /= 2;
        }
        return res;
    }
}lca;