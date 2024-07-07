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
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }

    void update(int x, node_t val){
        --x |= sz;
        tree[x] = val;
        while(x >>= 1){
            tree[x] = max(tree[x<<1], tree[x<<1|1]);
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
            if(l & 1) res1 = max(res1, tree[l++]);
            if(~r & 1) res2 = max(res2, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return max(res1, res2);
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
        seg.init(n);
        for(int i=1; i<=n; i++){
            seg.add(in[i], 0);
        }
        seg.construct();
    }

    void update(int i, int val){
        seg.update(in[i], val);
    }

    T query(int a, int b){
        int ret = 0;
        while(top[a] ^ top[b]){
            if(depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            ret = max(ret, seg.query(in[st], in[a]));
            a = parent[st];
        }
        if(depth[a] > depth[b]) swap(a, b);
        ret = max(ret, seg.query(in[adj[a][0]], in[b]));
        return ret;
    }
};