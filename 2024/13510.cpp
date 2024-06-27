#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

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

    void update(int i, node_t val){
        --i |= sz;
        tree[i] = val;
        while(i >>= 1){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
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

int sz[100010], depth[100010], parent[100010], top[100010], in[100010], out[100010];
int chk[100010], pv, cost[100010];
vector<pii> input, g[100010];
vector<int> adj[100010];

void dfs(int cur = 1)
{
    chk[cur] = 1;
    for(auto [next, nextCost]: g[cur]){
        if(chk[next]) continue;
        chk[next] = 1;
        dfs(next);
        adj[cur].push_back(next);
        cost[next] = nextCost;
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
int N;

void init()
{
    top[1] = 1;
    dfs(); dfs1(); dfs2();
    seg.init(N);
    for(int i=1; i<=N; i++){
        seg.add(in[i], cost[i]);
    }
    seg.construct();
}

void update(int i, int val)
{
    auto [a, b] = input[i-1];
    if(depth[a] < depth[b]) swap(a, b);
    seg.update(in[a], val);
}

int query(int a, int b)
{
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, seg.query(in[st], in[a]));
        a = parent[st];
    }
    if(a == b) return ret;
	if(depth[a] > depth[b]) swap(a, b);
	int next = -1;
	for(auto i: adj[a]) {
		if(top[i] == top[a]) next = i;
	}
	ret = max(ret, seg.query(in[next], in[b]));
	return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        input.push_back({u, v});
    }
    init();
    int Q; cin >> Q;
    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) update(a, b);
        else cout << query(a, b) << '\n';
    }

    return 0;
}