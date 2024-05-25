#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct Edge
{
    int from;
    int to;
    int cost;
    bool operator < (const Edge& other) const{
        return cost < other.cost;
    }
};

struct UnionFind
{
    int prev[200010];
    void init()
    {
        for(int i=1; i<=200000; i++){
            prev[i] = i;
        }
    }
    int Find(int x)
    {
        return x == prev[x] ? x : prev[x] = Find(prev[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x == y) return;
        prev[y] = x;
    }
};

const int MAX = 19;
int N, M;
int parent[200010][MAX], depth[200010], maxCost[200010][MAX];
vector<pii> tree[200010];
vector<Edge> adj(200010), query(200010);

void makeTree(int cur)
{
    for(auto [next, cost]: tree[cur]){
        if(depth[next] == -1){
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            maxCost[next][0] = cost;
            makeTree(next);
        }
    }
}

int lca(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    int res = 0;
    for(int i=0; diff; i++){
        if(diff % 2){
            res = max(res, maxCost[u][i]);
            u = parent[u][i];
        }
        diff /= 2;
    }
    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                res = max({res, maxCost[u][i], maxCost[v][i]});
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        res = max({res, maxCost[u][0], maxCost[v][0]});
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> adj[i].from >> adj[i].to >> adj[i].cost;
        query[i] = adj[i];
    }
    sort(adj.begin(), adj.begin() + M);
    
    UnionFind UF;
    UF.init();
    ll sum = 0;
    for(int i=0; i<M; i++){
        int x = adj[i].from;
        int y = adj[i].to;
        int c = adj[i].cost;
        if(UF.Find(x) != UF.Find(y)){
            UF.Union(x, y);
            tree[x].push_back({y, c});
            tree[y].push_back({x, c});
            sum += c;
        }
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    makeTree(1);
    for(int i=0; i<=MAX-2; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] == -1) continue;
            parent[j][i+1] = parent[parent[j][i]][i];
            maxCost[j][i+1] = max(maxCost[j][i], maxCost[parent[j][i]][i]);
        }
    }

    for(int i=0; i<M; i++){
        int x = query[i].from;
        int y = query[i].to;
        int c = query[i].cost;
        if(x == parent[y][0] || y == parent[x][0]) cout << sum << '\n';
        else cout << sum - lca(x, y) + c << '\n';
    }

    return 0;
}