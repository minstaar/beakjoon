#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> adj[100010];
int in[100010], out[100010];
int pv;

void dfs(int cur)
{
    in[cur] = ++pv;
    for(auto next: adj[cur]){
        dfs(next);
    }
    out[cur] = pv;
}

void propagate(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end)
{
    if(!lazy[node]) return;
    tree[node] += lazy[node];
    if(start != end){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int left, int right, int val)
{
    propagate(tree, lazy, node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        lazy[node] += val;
        propagate(tree, lazy, node, start, end);
        return;
    }
    int mid = start + end >> 1;
    update(tree, lazy, node * 2, start, mid, left, right, val);
    update(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(vector<ll>& tree, vector<ll>& lazy, int node, int start, int end, int index)
{
    propagate(tree, lazy, node, start, end);
    if(index < start || index > end) return 0;
    if(start == end) return tree[node];
    int mid = start + end >> 1;
    return query(tree, lazy, node * 2, start, mid, index) + query(tree, lazy, node * 2 + 1, mid + 1, end, index);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin>> N >> M;
    vector<ll> tree(N*4), lazy(N*4);
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        if(a != -1) adj[a].push_back(i);
    }
    dfs(1);

    for(int i=0; i<M; i++){
        int a; cin >> a;
        if(a == 1){
            int b, c; cin >> b >> c;
            update(tree, lazy, 1, 0, N - 1, in[b] - 1, out[b] - 1, c);
        }
        if(a == 2){
            int b; cin >> b;
            cout << query(tree, lazy, 1, 0, N - 1, in[b] - 1) << '\n';
        }
    }

    return 0;
}