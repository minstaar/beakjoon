#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

struct Node
{
    int l, r;
    ll sz, val;
    Node(): l(-1), r(-1), sz(0), val(0) {}
};

int N, Q, D;
int arr[100010];
ll pw[100010], count[100010];
vector<Node> tree;

void update(int node, int s, int e, int idx, int val)
{
    if(s == e){
        tree[node].sz += val;
        tree[node].val = (count[tree[node].sz] * idx) % MOD;
        return;
    }
    int m = s + e >> 1;
    if(idx <= m){
        if(tree[node].l == -1){
            tree[node].l = tree.size();
            tree.emplace_back();
        }
        update(tree[node].l, s, m, idx, val);
    }
    else{
        if(tree[node].r == -1){
            tree[node].r = tree.size();
            tree.emplace_back();
        }
        update(tree[node].r, m+1, e, idx, val);
    }
    ll lsz = 0, lval = 0;
    ll rsz = 0, rval = 0;
    if(tree[node].l != -1){
        lsz = tree[tree[node].l].sz;
        lval = tree[tree[node].l].val;
    }
    if(tree[node].r != -1){
        rsz = tree[tree[node].r].sz;
        rval = tree[tree[node].r].val;
    }
    tree[node].sz = lsz + rsz;
    tree[node].val = (rval * pw[lsz] + lval) % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q >> D;
    pw[0] = 1;
    for(int i=1; i<=100000; i++){
        pw[i] = (pw[i-1] * D) % MOD;
    }
    count[1] = 1;

    for(int i=2; i<=100000; i++){
        count[i] = (count[i-1] * D + 1) % MOD;
    }

    tree.emplace_back();
    for(int i=0; i<N; i++){
        cin >> arr[i];
        update(0, 0, 1e9, arr[i], 1);
    }
    cout << tree[0].val << '\n';
    while(Q--){
        int idx, val; cin >> idx >> val;
        update(0, 0, 1e9, arr[idx-1], -1);
        arr[idx-1] = val;
        update(0, 0, 1e9, val, 1);
        cout << tree[0].val << '\n';
    }

    return 0;
}