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
        --x |= sz;
        tree[x] = val;
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void update(int i, node_t val){
        --i |= sz;
        tree[i] = val;
        while(i >>= 1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    node_t get(int x){
        --x |= sz;
        return tree[x];
    }

    node_t query(int l, int r){
        --l |= sz, --r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 += tree[l++];
            if(~r & 1) res2 += tree[r--];
            l >>= 1, r >>= 1;
        }
        return res1 + res2;
    }
};

int sz[200010], depth[200010], parent[200010], top[200010], in[200010];
int N, pv;
vector<int> adj[200010];
SegmentTree<int> seg;

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

void init()
{
    top[1] = 1;
    dfs1(); dfs2();
    seg.init(N);
    for(int i=1; i<=N; i++){
        seg.add(in[i], 1);
    }
    seg.construct();
}

void update(int x)
{
    seg.update(in[x], 0);
}

bool query(int a, int b)
{
    int u = a, v = b;
    int sum = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        sum += seg.query(in[st], in[a]);
        a = parent[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    sum += seg.query(in[adj[a][0]], in[b]);
    return sum == depth[u] + depth[v] - 2 * depth[a];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q; cin >> N >> Q;
    for(int i=2; i<=N; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }
    init();
    while(Q--){
        int u, v, op; cin >> u >> v >> op;
        if(op == 0){
            cout << (query(u, v) ? "YES" : "NO") << '\n';
        }
        else{
            if(query(u, v)){
                cout << "YES" << '\n';
                update(u);
            }
            else{
                cout << "NO" << '\n';
                update(v);
            }
        }
    }

    return 0;
}