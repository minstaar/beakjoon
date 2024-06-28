#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent;
    
    UnionFind(int n): parent(n, -1) {}

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y) return 0;
        parent[x] += parent[y];
        parent[y] = x;
        return 1;
    }
};

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

int chk[30010], sz[30010], depth[30010], parent[30010], top[30010], in[30010];
int N, Q, pv, arr[30010];
vector<int> input[30010], adj[30010];
vector<tuple<string, int, int>> qry;
SegmentTree<int> seg;

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
}

void init()
{
    top[1] = 1;
    dfs(); dfs1(); dfs2();
    seg.init(N);
    for(int i=1; i<=N; i++){
        seg.add(in[i], arr[i]);
    }
    seg.construct();
}

void update(int i, int val)
{
    seg.update(in[i], val);
}

int query(int a, int b)
{
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret += seg.query(in[st], in[a]);
        a = parent[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret += seg.query(in[a], in[b]);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    UnionFind UF(N+1);
    cin >> Q;
    for(int i=0; i<Q; i++){
        string op; int a, b; cin >> op >> a >> b;
        if(op == "bridge" && UF.Union(a, b)){
            input[a].push_back(b);
            input[b].push_back(a);
        }
        qry.push_back({op, a, b});
    }
    for(int i=2; i<=N; i++){
        if(UF.Union(1, i)){
            input[1].push_back(i);
            input[i].push_back(1);
        }
    }
    init();

    UnionFind UF2(N+1);
    for(int i=0; i<Q; i++){
        auto [op, a, b] = qry[i];
        if(op == "bridge"){
            if(UF2.Union(a, b)) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
        else if(op == "penguins"){
            update(a, b);
        }
        else{
            if(UF2.Find(a) != UF2.Find(b)) cout << "impossible" << '\n';
            else cout << query(a, b) << '\n';
        }
    }

    return 0;
}