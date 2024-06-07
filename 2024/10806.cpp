#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
struct UnionFind
{
    vector<int> parent;
    void init(int n){
        parent = vector<int>(n, -1);
    }
    int Find(int x)
    {
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x != y){
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
};

vector<pii> adj[100010];
vector<pii> edge;
int dfn[100010], id;
UnionFind UF;
vector<int> bccTree[100010];
vector<int> leaf;

int dfs(int prevIdx, int cur)
{
    int ret = dfn[cur] = ++id;
    for(auto [next, idx]: adj[cur]){
        if(idx == prevIdx) continue;
        if(dfn[next] == 0){
            int low = dfs(idx, next);
            if(low > dfn[cur]){
                edge.push_back({cur, next});
            }
            else UF.Union(cur, next);
            ret = min(ret, low);
        }
        else ret = min(ret, dfn[next]);
    }
    return ret;
}

void treeDFS(int prev, int cur)
{
    if(bccTree[cur].size() == 1){
        leaf.push_back(cur);
    }
    for(auto next: bccTree[cur]){
        if(next == prev) continue;
        treeDFS(cur, next);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    UF.init(N+1);
    for(int i=1; i<=N; i++){
        if(dfn[i] == 0) dfs(-1, i);
    }

    for(auto [u, v]: edge){
        u = UF.Find(u);
        v = UF.Find(v);
        bccTree[u].push_back(v);
        bccTree[v].push_back(u);
    }

    int s = UF.Find(1);
    treeDFS(-1, s);
    int sz = leaf.size();
    cout << (sz + 1) / 2 << '\n';
    for(int i=0; i<sz/2; i++){
        cout << leaf[i] << ' ' << leaf[i+sz/2] << '\n';
    }
    if(sz % 2) cout << leaf[0] << ' ' << leaf[sz-1] << '\n';

    return 0;
}