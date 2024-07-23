#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll sz = 1 << 20;
ll tree[sz * 2];

void add(int x, int val)
{
    tree[x|sz] = val;
}

void construct()
{
    for(int i=sz-1; i>0; i--){
        tree[i] = (tree[i<<1] * tree[i<<1|1]) % MOD;
    }
}

void update(int x, int val)
{
    tree[x|=sz] = val;
    while(x >>= 1) tree[x] = (tree[x<<1] * tree[x<<1|1]) % MOD;
}

ll query(int l, int r)
{
    l |= sz, r |= sz;
    ll ret = 1;
    while(l <= r){
        if(l & 1) ret = (ret * tree[l++]) % MOD;
        if(~r & 1) ret = (ret * tree[r--]) % MOD;
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    int Q = M + K;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        add(i, a);
    }
    construct();
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int idx, val; cin >> idx >> val;
            update(idx - 1, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << query(l - 1, r - 1) << '\n';
        }
    }

    return 0;
}