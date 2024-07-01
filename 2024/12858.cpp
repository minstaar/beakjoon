#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct LazySeg{
    ll tree[400010], lazy[400010];

    void propagate(int node, int s,  int e){
        if(lazy[node] == 0) return;
        tree[node] += (e - s + 1) * lazy[node];
        if(s ^ e){
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(int node, int s, int e, int l, int r, int v){
        propagate(node, s, e);
        if(l > e || r < s) return;
        if(l <= s && e <= r){
            lazy[node] += v;
            propagate(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, l, r, v);
        update(node<<1|1, m+1, e, l, r, v);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    ll query(int node, int s, int e, int idx){
        propagate(node, s, e);
        if(idx < s || idx > e) return 0;
        if(s == e) return tree[node];
        int m = s + e >> 1;
        return query(node<<1, s, m, idx) + query(node<<1|1, m+1, e, idx);
    }
};

ll gcd(ll a, ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    return __gcd(a, b);
}
    

struct SegmentTree{
    ll tree[400010];
    int sz;

    SegmentTree(){
        for(sz=1; sz<100010; sz<<=1);
    }

    void update(int x, ll v){
        x |= sz;
        tree[x] = v;
        while(x >>= 1){
            tree[x] = gcd(tree[x<<1], tree[x<<1|1]);
        }
    }
    
    ll query(int l, int r){
        l |= sz, r |= sz;
        ll ret = 0;
        while(l <= r){
            if(l & 1) ret = gcd(ret, tree[l++]);
            if(~r & 1) ret = gcd(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
};

LazySeg Seg1;
SegmentTree Seg2;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N; i++){
        ll a; cin >> a;
        Seg1.update(1, 1, N, i, i, a);
    }
    for(int i=1; i<N; i++){
        ll t = Seg1.query(1, 1, N, i) - Seg1.query(1, 1, N, i+1);
        Seg2.update(i, abs(t));
    }
    int Q; cin >> Q;
    while(Q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 0){
            ll t = Seg2.query(a, b-1);
            cout << gcd(Seg1.query(1, 1, N, a), t) << '\n';
        }
        else{
            Seg1.update(1, 1, N, a, b, op);
            ll t = Seg1.query(1, 1, N, a-1) - Seg1.query(1, 1, N, a);
            Seg2.update(a-1, abs(t));
            t = Seg1.query(1, 1, N, b) - Seg1.query(1, 1, N, b+1);
            Seg2.update(b, abs(t));
        }
    }

    return 0;
}