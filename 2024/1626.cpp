#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct UnionFind{
    vector<int> parent;

    UnionFind(int n): parent(n+1, -1){}

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        x = Find(x), y = Find(y);
        if(x != y){
            parent[x] += parent[y];
            parent[y] = x;
            return true;
        }
        return false;
    }
};

struct Edge{
    int from, to, cost;
    bool operator < (const Edge& other) const{
        return cost < other.cost;
    }
};

struct LCA{
    vector<vector<pii>> adj;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<vector<int>> dist, dist2;
    int n, log;

    void init(int _n){
        n = _n;
        for(; (1<<log)<=n; log++);
        log++;        
        adj = vector<vector<pii>>(n+1);
        depth = vector<int>(n+1, -1);
        parent = vector<vector<int>>(n+1, vector<int>(log, -1));
        dist = vector<vector<int>>(n+1, vector<int>(log));
        dist2 = vector<vector<int>>(n+1, vector<int>(log));
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
                dist[next][0] = cost;
                dist2[next][0] = cost;
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
                    if(parent[j][i+1] == -1) continue;
                    dist[j][i+1] = max(dist[parent[j][i]][i], dist[j][i]);
                    set<int, greater<int>> tmp;
                    tmp.insert(dist[parent[j][i]][i]);
                    tmp.insert(dist[j][i]);
                    tmp.insert(dist2[parent[j][i]][i]);
                    tmp.insert(dist2[j][i]);
                    if(tmp.size() == 1) dist2[j][i+1] = *tmp.begin();
                    else dist2[j][i+1] = *next(tmp.begin());
                }
            }
        }
    }

    pii get_lca(int u, int v){
        set<int, greater<int>> res;
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=0; diff; i++){
            if(diff % 2){
                res.insert(dist[u][i]);
                res.insert(dist2[u][i]);
                u = parent[u][i];
            }
            diff /= 2;
        }
        if(u != v){
            for(int i=log-1; i>=0; i--){
                if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                    res.insert(dist[u][i]);
                    res.insert(dist[v][i]);
                    res.insert(dist2[u][i]);
                    res.insert(dist2[v][i]);
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            res.insert(dist[u][0]);
            res.insert(dist[v][0]);
            res.insert(dist2[u][0]);
            res.insert(dist2[v][0]);
            u = parent[u][0];
        }
        if(res.size() == 1) return {*res.begin(), *res.begin()};
        else return {*res.begin(), *next(res.begin())};
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V, E; cin >> V >> E;
    vector<Edge> edges(E);
    LCA lca;
    lca.init(V);
    for(int i=0; i<E; i++){
        int u, v, c; cin >> u >> v >> c;
        edges[i] = {u, v, c};
    }
    sort(edges.begin(), edges.end());
    
    ll mst = 0, ans = LLONG_MAX;
    vector<Edge> exclude;
    UnionFind UF(V);
    for(auto [u, v, c]: edges){
        if(UF.Union(u, v)){
            lca.addEdge(u, v, c);
            mst += c;
        }
        else exclude.push_back({u, v, c});
    }

    if(E - exclude.size() != V - 1 || V == 1){
        cout << -1 << '\n';
    }
    else{
        lca.setParent();
        for(auto [u, v, c]: exclude){
            pii res = lca.get_lca(u, v);
            if(c - res.first > 0) ans = min(ans, mst + c - res.first);
            else if(c - res.second > 0) ans = min(ans, mst + c - res.second);
        }
    
        if(ans == LLONG_MAX || ans <= mst) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}