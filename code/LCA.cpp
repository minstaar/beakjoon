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
        for(; (1<<log)<=n; log++);
        log++;        
        adj = vector<vector<pii>>(n+1);
        depth = vector<int>(n+1);
        parent = vector<vector<int>>(n+1, vector<int>(log));
        dist = vector<vector<Data>>(n+1, vector<Data>(log));
    }

    void addEdge(int u, int v, int c){
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    void build(){
        queue<int> que;
        que.push(1);
        depth[1] = 1;
        while(!que.empty()){
            int cur = que.front(); que.pop();
            for(auto [next, cost]: adj[cur]){
                if(!depth[next]){
                    depth[next] = depth[cur] + 1;
                    parent[next][0] = cur;
                    dist[next][0] = {cost, cost, cost};
                    que.push(next);
                }
            }
        }
        for(int i=1; i<log; i++){
            for(int j=1; j<=n; j++){
                parent[j][i] = parent[parent[j][i-1]][i-1];
                dist[j][i].min = min(dist[parent[j][i-1]][i-1].min, dist[j][i-1].min);
                dist[j][i].max = max(dist[parent[j][i-1]][i-1].max, dist[j][i-1].max);
                dist[j][i].sum = dist[parent[j][i-1]][i-1].sum + dist[j][i-1].sum;
            }
        }
    }

    int get_lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        for(int i=log-1; i>=0; i--){
            if(depth[u] - depth[v] >= (1 << i)) u = parent[u][i];
        }
        if(u != v){
            for(int i=log-1; i>=0; i--){
                if(parent[u][i] != parent[v][i]){
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
        for(int i=log-1; i>=0; i--){
            if(depth[u] - depth[a] >= (1 << i)){
                res.sum += dist[u][i].sum;
                res.min = min(res.min, dist[u][i].min);
                res.max = max(res.max, dist[u][i].max);
                u = parent[u][i];
            }
        }
        for(int i=log-1; i>=0; i--){
            if(depth[v] - depth[a] >= (1 << i)){
                res.sum += dist[v][i].sum;
                res.min = min(res.min, dist[v][i].min);
                res.max = max(res.max, dist[v][i].max);
                v = parent[v][i];
            }
        }
        return res;
    }
};