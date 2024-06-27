#include <bits/stdc++.h>
using namespace std;

template<typename node_t> struct SegmentTree{
    int sz;
    vector<node_t> tree;
    
    void init(int n){
        for(sz=1; sz<n; sz<<=1);
        tree = vector<node_t>(sz<<1);
    }

    void add(int x, node_t val){
        x |= sz;
        tree[x] = val;
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void update(int i, node_t val){
        i |= sz;
        tree[i] = val;
        while(i >>= 1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    node_t get(int x){
        return tree[x|sz];
    }

    node_t query(int l, int r){
        l |= sz, r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 += tree[l++];
            if(~r & 1) res2 += tree[r--];
            l >>= 1, r >>= 1;
        }
        return res1 + res2;
    }
};

int sz[100010], depth[100010], parent[100010], top[100010], in[100010], out[100010];
int chk[100010], pv = 0;
vector<int> inp[100010], adj[100010];

void dfs(int cur = 1)
{
    chk[cur] = 1;
    for(auto next: inp[cur]) if(!chk[next]){
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
}

SegmentTree<int> seg;
int N, arr[100010];

void init()
{
    dfs(); dfs1(); dfs2();
    seg.init(N);
}

void update(int v)
{
    arr[v] ^= 1;
    seg.update(in[v], arr[v]);
}

int query(int v)
{
    if(seg.get(1)) return 1;
    int ret = -1;
    while(top[v] != top[1]){
        int st = top[v];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        inp[u].push_back(v);
        inp[v].push_back(u);
    }
    init();
    int Q; cin >> Q;
    while(Q--){
        int op, v; cin >> op >> v;
        if(op == 1) update(v);
        else cout << query(v) << '\n';
    }
}