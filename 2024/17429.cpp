#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = unsigned long long;

const ll MOD = 1LL << 32;

struct SegmentTree{
    ll tree[2000010], lazy[2000010][2];

    void propagate(int node, int start, int end){
        if(lazy[node][0] == 1 && lazy[node][1] == 0) return;
        tree[node] *= lazy[node][0]; tree[node] %= MOD;
        tree[node] += (end - start + 1) * lazy[node][1]; tree[node] %= MOD;
        if(start ^ end){
            lazy[node<<1][0] *= lazy[node][0]; lazy[node<<1][0] %= MOD;
            lazy[node<<1][1] *= lazy[node][0]; lazy[node<<1][1] %= MOD;
            lazy[node<<1][1] += lazy[node][1]; lazy[node<<1][1] %= MOD;

            lazy[node<<1|1][0] *= lazy[node][0]; lazy[node<<1|1][0] %= MOD;
            lazy[node<<1|1][1] *= lazy[node][0]; lazy[node<<1|1][1] %= MOD;
            lazy[node<<1|1][1] += lazy[node][1]; lazy[node<<1|1][1] %= MOD;
        }
        lazy[node][0] = 1;
        lazy[node][1] = 0;
    }

    void update_range(int node, int start, int end, int left, int right, ll a, ll b){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node][0] *= a; lazy[node][0] %= MOD;
            lazy[node][1] *= a; lazy[node][1] %= MOD;
            lazy[node][1] += b; lazy[node][1] %= MOD;
            propagate(node, start, end);
            return;
        }
        
        int mid = start + end >> 1;
        update_range(node<<1, start, mid, left, right, a, b);
        update_range(node<<1|1, mid+1, end, left, right, a, b);
        tree[node] = tree[node<<1] + tree[node<<1|1];
        tree[node] %= MOD;
    }

    ll query(int node, int start, int end, int left, int right){
        propagate(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        int mid = start + end >> 1;
        return (query(node<<1, start, mid, left, right) + query(node<<1|1, mid+1, end, left, right)) % MOD;
    }
}seg;

int chk[500010], sz[500010], depth[500010], parent[500010], top[500010], in[500010], out[500010];
int N, pv;
vector<int> input[500010], adj[500010];

void dfs(int cur = 1)
{
    chk[cur] = 1;
    for(auto next: input[cur]){
        if(chk[next]) continue;
        chk[next] = 1;
        dfs(next);
        adj[cur].push_back(next);
    }
}

void dfs1(int cur = 1)
{
    sz[cur] = 1;
    for(auto &next: adj[cur]){
        depth[next] = depth[cur] + 1;
        parent[next] = cur;
        dfs1(next);
        sz[cur] += sz[next];
        if(sz[next] > sz[adj[cur][0]]) swap(next, adj[cur][0]);
    }
}

void dfs2(int cur = 1)
{
    in[cur] = ++pv;
    for(auto next: adj[cur]){
        top[next] = (next == adj[cur][0] ? top[cur] : next);
        dfs2(next);
    }
    out[cur] = pv;
}

void updateSub(int x, ll a, ll b)
{
    seg.update_range(1, 0, N-1, in[x]-1, out[x]-1, a, b);
}

void updatePath(int x, int y, ll a, ll b)
{
    while(top[x] ^ top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        int st = top[x];
        seg.update_range(1, 0, N-1, in[st]-1, in[x]-1, a, b);
        x = parent[st];
    }
    if(depth[x] > depth[y]) swap(x, y);
    seg.update_range(1, 0, N-1, in[x]-1, in[y]-1, a, b);
}

ll querySub(int x)
{
    return seg.query(1, 0, N-1, in[x]-1, out[x]-1);
}

ll queryPath(int x, int y)
{
    ll ret = 0;
    while(top[x] ^ top[y]){
        if(depth[top[x]] < depth[top[y]]) swap(x, y);
        int st = top[x];
        ret += seg.query(1, 0, N-1, in[st]-1, in[x]-1);
        ret %= MOD;
        x = parent[st];
    }
    if(depth[x] > depth[y]) swap(x, y);
    ret += seg.query(1, 0, N-1, in[x]-1, in[y]-1);
    ret %= MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q; cin >> N >> Q;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        input[u].push_back(v);
        input[v].push_back(u);
    }

    top[1] = 1;
    dfs(); dfs1(); dfs2();

    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int x, v; cin >> x >> v;
            updateSub(x, 1, v);
        }
        if(op == 2){
            int x, y, v; cin >> x >> y >> v;
            updatePath(x, y, 1, v);
        }
        if(op == 3){
            int x, v; cin >> x >> v;
            updateSub(x, v, 0);
        }
        if(op == 4){
            int x, y, v; cin >> x >> y >> v;
            updatePath(x, y, v, 0);
        }
        if(op == 5){
            int x; cin >> x;
            cout << querySub(x) << '\n';
        }
        if(op == 6){
            int x, y; cin >> x >> y;
            cout << queryPath(x, y) << '\n';
        }
    }

    return 0;
}