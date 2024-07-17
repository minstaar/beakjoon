#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename node_t> struct SegmentTree{
    vector<int> arr;
    vector<node_t> tree, lazy;
    
    void Init(int n){
        arr = vector<int>(n);
        tree = lazy = vector<node_t>(1<<((int)ceil(log2(n))+1));
    }

    node_t Merge(node_t l, node_t r){
        return l + r;
    }

    void init(int node, int s, int e){
        if(s == e){
            tree[node] = arr[s];
            return;
        }
        int m = s + e >> 1;
        init(node * 2, s, m), init(node * 2 + 1, m + 1, e);
        tree[node] = Merge(tree[node*2], tree[node*2+1]);
    }

    void propagate(int node, int s, int e){
        if(!lazy[node]) return;
        tree[node] += lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update_range(int node, int s, int e, int l, int r, node_t val){
        propagate(node, s, e);
        if(l > e || r < s) return;
        if(l <= s && e <= r){
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update_range(node * 2, s, m, l, r, val), update_range(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = Merge(tree[node*2], tree[node*2+1]);
    }

    node_t query(int node, int s, int e, int l, int r){
        propagate(node, s, e);
        if(l > e || r < s) return 0;
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        return Merge(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }
};

template<typename T> struct HLD{
    vector<int> chk, sz, depth, parent, top, in, out;
    vector<vector<int>> input, adj;
    SegmentTree<T> seg;
    int n, pv;

    HLD(int n): n(n), chk(n+1), sz(n+1), depth(n+1), parent(n+1), top(n+1), in(n+1), out(n+1), input(n+1), adj(n+1){}

    void dfs(int cur = 1){
        chk[cur] = 1;
        for(auto next: input[cur]){
            if(chk[next]) continue;
            chk[next] = 1;
            dfs(next);
            adj[cur].push_back(next);
        }
    }

    void dfs1(int cur = 1){
        sz[cur] = 1;
        for(auto &next: adj[cur]){
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            dfs1(next);
            sz[cur] += sz[next];
            if(sz[next] > sz[adj[cur][0]]) swap(next, adj[cur][0]);
        }
    }

    void dfs2(int cur = 1){
        in[cur] = ++pv;
        for(auto next: adj[cur]){
            top[next] = (next == adj[cur][0] ? top[cur] : next);
            dfs2(next);
        }
    }

    void init(){
        top[1] = 1;
        dfs(); dfs1(); dfs2();
        seg.Init(n);
    }

    void update(int a, int b){
        while(top[a] ^ top[b]){
            if(depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            seg.update_range(1, 1, n, in[st], in[a], 1);
            a = parent[st];
        }
        if(depth[a] > depth[b]) swap(a, b);
        seg.update_range(1, 1, n, in[adj[a][0]], in[b], 1);
    }

    T query(int a, int b){
        T ret = 0;
        while(top[a] ^ top[b]){
            if(depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            ret += seg.query(1, 1, n, in[st], in[a]);
            a = parent[st];
        }
        if(depth[a] > depth[b]) swap(a, b);
        ret += seg.query(1, 1, n, in[adj[a][0]], in[b]);
        return ret;
    }
};

HLD<ll> hld(100010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        hld.input[u].push_back(v);
        hld.input[v].push_back(u);
    }
    hld.init();

    while(M--){
        char op; cin >> op;
        if(op == 'P'){
            int a, b; cin >> a >> b;
            hld.update(a, b);
        }
        else{
            int a, b; cin >> a >> b;
            cout << hld.query(a, b) << '\n';
        }
    }

    return 0;
}