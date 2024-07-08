#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;

struct LiChaoTree{
    struct Line{
        ll m, b;
        ll f(ll x) {return m * x + b;}
        Line(ll m, ll b): m(m), b(b) {}
        Line(): Line(0, -INF) {}
    };
    struct Node{
        int l, r; Line line;
        Node(): l(-1), r(-1), line(0, -INF) {}
    };

    vector<Node> tree;

    void init(){
        tree.emplace_back();
    }

    void update(int node, ll s, ll e, Line v){
        Line lo = tree[node].line, hi = v;
        if(lo.f(s) > hi.f(s)) swap(lo, hi);
        if(lo.f(e) <= hi.f(e)){
            tree[node].line = hi;
            return;
        }
        ll m = s + e >> 1;
        if(lo.f(m) <= hi.f(m)){
            tree[node].line = hi;
            if(tree[node].r == -1){
                tree[node].r = tree.size();
                tree.emplace_back();
            }
            update(tree[node].r, m + 1, e, lo);
        }
        else{
            tree[node].line = lo;
            if(tree[node].l == -1){
                tree[node].l = tree.size();
                tree.emplace_back();
            }
            update(tree[node].l, s, m, hi);
        }
    }

    ll query(int node, ll s, ll e, ll x){
        if(node == -1) return -INF;
        ll t = tree[node].line.f(x);
        ll m = s + e >> 1;
        if(x <= m) return max(t, query(tree[node].l, s, m, x));
        else return max(t, query(tree[node].r, m + 1, e, x));
    }
}lichao;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll s = -1e12, e = 1e12;
    lichao.init();
    int Q; cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            ll a, b; cin >> a >> b;
            lichao.update(0, s, e, {a, b});
        }
        else{
            ll x; cin >> x;
            cout << lichao.query(0, s, e, x) << '\n';
        }
    }

    return 0;
}