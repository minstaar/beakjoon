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

    void update(int x, node_t val){
        --x |= sz;
        tree[x] = val;
        while(x >>= 1){
            tree[x] = tree[x<<1] + tree[x<<1|1];
        }
    }

    node_t get(int x){
        --x |= sz;
        return tree[x];
    }

    node_t sum(int l, int r){
        --l |= sz, --r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 += tree[l++];
            if(~r & 1) res2 += tree[r--];
            l >>= 1, r >>= 1;
        }
        return res1 + res2;
    }

    node_t query(int l, int r){
        if(sum(l, r) == 0) return -1;
        int ret = -1;
        while(l <= r){
            int m = l + r >> 1;
            if(sum(l, m)){
                ret = m;
                r = m -1;
            }
            else l = m + 1;
        }
        return ret;
    }
};

template<typename T> struct HLD{
    vector<int> sz, depth, parent, top, in, rev, chk, arr;
    vector<vector<int>> input, adj;
    SegmentTree<T> seg;
    int n, pv = 0;
    
    HLD(int n): n(n), sz(n+1), depth(n+1), parent(n+1), top(n+1), in(n+1), rev(n+1), chk(n+1), arr(n+1), input(n+1), adj(n+1){}

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
        rev[pv] = cur;
        for(auto next: adj[cur]){
            top[next] = (next == adj[cur][0] ? top[cur] : next);
            dfs2(next);
        }
    }

    void init(){
        top[1] = 1;
        dfs(); dfs1(); dfs2();
        seg.init(n);
    }

    void update(int i){
        arr[i] ^= 1;
        seg.update(in[i], arr[i]);
    }

    T query(int v){
        int ret = -1;
        while(top[v] ^ top[1]){
            int st = top[v];
            int tmp = seg.query(in[st], in[v]);
            if(tmp > 0) ret = tmp;
            v = parent[st];
        }
        int tmp = seg.query(in[1], in[v]);
        if(tmp > 0) ret = tmp;
        return ret > 0 ? rev[ret] : -1;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    HLD<int> hld(N);
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        hld.input[u].push_back(v);
        hld.input[v].push_back(u);
    }
    hld.init();

    int Q; cin >> Q;
    while(Q--){
        int op, a; cin >> op >> a;
        if(op == 1) hld.update(a);
        else cout << hld.query(a) << '\n';
    }

    return 0;
}