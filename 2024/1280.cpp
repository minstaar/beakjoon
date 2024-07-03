#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

struct SegmentTree{
    struct Data{
        ll cnt;
        ll sum;
    };
    Data tree[800010];

    void update(int node, int s, int e , int idx, int val){
        if(idx < s || idx > e) return;
        tree[node].cnt += val;
        tree[node].sum += idx;
        if(s ^ e){
            int m = s + e >> 1;
            update(node<<1, s, m, idx, val);
            update(node<<1|1, m+1, e, idx, val);
            tree[node].cnt = tree[node<<1].cnt + tree[node<<1|1].cnt;
            tree[node].sum = tree[node<<1].sum + tree[node<<1|1].sum;
        }
    }

    Data query(int node, int s, int e, int l, int r){
        if(l > e || r < s) return {0, 0};
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        Data a = query(node<<1, s, m, l, r);
        Data b = query(node<<1|1, m+1, e, l, r);
        return {a.cnt + b.cnt, a.sum + b.sum};
    }
};

SegmentTree seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    ll res = 1;
    for(int i=0; i<N; i++){
        ll x; cin >> x;
        if(i > 0){
            auto [lcnt, ldist] = seg.query(1, 0, 200000, 0, x);
            ll t = (x * lcnt - ldist) % MOD;
            auto [rcnt, rdist] = seg.query(1, 0, 200000, x, 200000);
            t = (t + rdist - x * rcnt) % MOD;
            res = (res * t) % MOD;
        }
        seg.update(1, 0, 200000, x, 1);
    }
    cout << res << '\n';

    return 0;
}