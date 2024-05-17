#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int in[200010], out[200010], depth[200010], pv;
vector<int> adj[200010];

void makeTree(int cur)
{
    in[cur] = ++pv;
    for(auto next: adj[cur]){
        if(depth[next] != 0) continue;
        depth[next] = depth[cur] + 1;
        makeTree(next);
    }
    out[cur] = pv;
}

void update(vector<ll>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    tree[node] += val;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, val);
        update(tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

ll sum(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, C; cin >> N >> C;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[C] = 1;
    makeTree(C);

    vector<ll> tree(N*4);
    int Q; cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b;
        if(a == 1){
            update(tree, 1, 0, N - 1, in[b] - 1, 1);
        }
        if(a == 2){
            cout << sum(tree, 1, 0, N - 1, in[b] - 1, out[b] - 1) * depth[b] << '\n';
        }
    }

    return 0;
}