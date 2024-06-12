#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;
struct Data{
    int min = INF;
    int max = -INF;
    long long sum = 0;
};

struct LCA{
    vector<vector<pii>> adj;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<Data>> dist;
    int n, log;

    void init(int _n){
        n = _n;
        adj.clear();
        adj.resize(n+1);
        for(; (1<<log)<=n; log++);
        log++;
        parent.resize(n+1, vector<int>(log, -1));
        dist.resize(n+1, vector<Data>(log));
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

    int get_lca(int u, int v, Data& cost){
        cost = {INF, -INF, 0};
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=0; diff; i++){
            if(diff % 2){
                cost.min = min(cost.min, dist[u][i].min);
                cost.max = max(cost.max, dist[u][i].max);
                cost.sum += dist[u][i].sum;
                u = parent[u][i];
            }
            diff /= 2;
        }
        if(u != v){
            for(int i = log-1; i>=0; i--){
                if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                    cost.min = min({cost.min, dist[u][i].min, dist[v][i].min});
                    cost.max = max({cost.max, dist[u][i].max, dist[v][i].max});
                    cost.sum = dist[u][i].sum + dist[v][i].sum;
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            cost.min = min({cost.min, dist[u][0].min, dist[v][0].min});
            cost.max = max({cost.max, dist[u][0].max, dist[v][0].max});
            cost.sum = dist[u][0].sum + dist[v][0].sum;
            u = parent[u][0];
        }
        return u;
    }
}lca;