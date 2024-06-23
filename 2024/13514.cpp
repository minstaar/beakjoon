#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX = 20;
int sz[100010], cent_parent[100010], dp[100010][20], depth[100010];
bool visited[100010], color[100010];
vector<int> adj[100010];
multiset<int> st[100010];

int getSize(int prev, int cur)
{
    sz[cur] = 1;
    for(auto next: adj[cur]){
        if(next != prev && !visited[next]){
            sz[cur] += getSize(cur, next);
        }
    }
    return sz[cur];
}

int getCent(int prev, int cur, int cnt)
{
    for(auto next: adj[cur]){
        if(next != prev && !visited[next] && sz[next] * 2 > cnt){
            return getCent(cur, next, cnt);
        }
    }
    return cur;
}

void init(int prev, int cur)
{
    int cent = getCent(prev, cur, getSize(prev, cur));
    visited[cent] = true;
    cent_parent[cent] = (prev == -1 ? cent : prev);
    for(auto next: adj[cent]){
        if(!visited[next]) init(cent, next);
    }
}

void dfs(int cur)
{
    for(auto next: adj[cur]){
        if(!depth[next]){
            depth[next] = depth[cur] + 1;
            dp[next][0] = cur;
            dfs(next);
        }
    }
}

int lca(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=19; i>=0; i--){
        if(depth[u] - depth[v] >= (1 << i)) u = dp[u][i];
    }
    if(u == v) return u;
    for(int i=19; i>=0; i--){
        if(dp[u][i] ^ dp[v][i]) u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

int getDist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void update(int v)
{
    color[v] ^= 1;
    int cur = v;
    while(1){
        int dist = getDist(v, cur);
        if(color[v]) st[cur].insert(dist);
        else st[cur].erase(st[cur].find(dist));
        if(cur == cent_parent[cur]) break;
        cur = cent_parent[cur];
    }
}

int query(int v)
{
    int ret = 1e9;
    int cur = v;
    while(1){
        int dist = getDist(v, cur);
        if(!st[cur].empty()) ret = min(ret, dist + *st[cur].begin());
        if(cur == cent_parent[cur]) break;
        cur = cent_parent[cur];
    }
    if(ret == 1e9) return -1;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(-1, 0);
    
    depth[0] = 1;
    dfs(0);
    for(int i=1; i<19; i++){
        for(int j=0; j<N; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    int M; cin >> M;
    while(M--){
        int a, b; cin >> a >> b;
        if(a == 1) update(b-1);
        else cout << query(b-1) << '\n';
    }

    return 0;
}