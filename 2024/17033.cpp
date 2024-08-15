#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTree{
    int sz = 1 << 17;
    int tree[1<<18];

    void add(int x, int val){
        tree[x|=sz] = val;
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i] = tree[i<<1] ^ tree[i<<1|1];
        }
    }

    void update(int x, int val){
        tree[x|=sz] = val;
        while(x >>= 1) tree[x] = tree[x<<1] ^ tree[x<<1|1];
    }

    int query(int l, int r){
        l |= sz, r |= sz;
        int ret = 0;
        while(l <= r){
            if(l & 1) ret ^= tree[l++];
            if(~r & 1) ret ^= tree[r--];
            l >>= 1, r >>= 1;
        }
        return ret;
    }
};

const int MAX = 100010;
int N, Q, arr[MAX], pv;
int chk[MAX], sz[MAX], depth[MAX], parent[MAX], top[MAX], in[MAX];
vector<int> input[MAX], adj[MAX];
SegmentTree seg;

void dfs(int cur = 1)
{
    chk[cur] = 1;
    for(auto next: input[cur]) if(!chk[next]){
        chk[next] = 1;
        adj[cur].push_back(next);
        dfs(next);
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

void update(int x, int val)
{
    seg.update(in[x], val);
}

int query(int a, int b)
{
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret ^= seg.query(in[st], in[a]);
        a = parent[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret ^= seg.query(in[a], in[b]);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        input[u].push_back(v);
        input[v].push_back(u);
    }

    top[1] = 1;
    dfs(); dfs1(); dfs2();
    for(int i=1; i<=N; i++) seg.add(in[i], arr[i]);
    seg.construct();

    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int i, val; cin >> i >> val;
            update(i, val);
        }
        else{
            int i, j; cin >> i >> j;
            cout << query(i, j) << '\n';
        }
    }

    return 0;
}