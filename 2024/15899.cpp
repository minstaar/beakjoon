#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;

struct MergeSortTree
{
    const int sz = 1 << 18;
    vector<int> tree[1<<19];
    void add(int x, int v)
    {
        x |= sz;
        tree[x].push_back(v);
    }
    void construct()
    {
        for(int i=sz-1; i>0; i--){
            tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
            merge(all(tree[i<<1]), all(tree[i<<1|1]), tree[i].begin());
        }
    }
    int query(int l, int r, int k)
    {
        --l |= sz, --r |= sz;
        int res = 0;
        while(l <= r){
            if(l & 1){
                res += upper_bound(all(tree[l]), k) - tree[l].begin();
                l++;
            }
            if(~r & 1){
                res += upper_bound(all(tree[r]), k) - tree[r].begin();
                r--;
            }
            l >>= 1, r >>= 1;
        }
        return res;
    }
}seg;

const int MOD = 1e9 + 7;
int color[200010], in[200010], out[200010], pv;
vector<int> adj[200010];

void makeTree(int prev, int cur)
{
    in[cur] = ++pv;
    seg.add(pv - 1, color[cur]);
    for(auto next: adj[cur]){
        if(next != prev){
            makeTree(cur, next);
        }
    }
    out[cur] = pv;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, C; cin >> N >> M >> C;

    for(int i=1; i<=N; i++) cin >> color[i];
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(0, 1);
    seg.construct();

    int ans = 0;
    for(int i=1; i<=M; i++){
        int a, b; cin >> a >> b;
        ans = (ans + seg.query(in[a], out[a], b)) % MOD;
    }
    cout << ans << '\n';

    return 0;
}