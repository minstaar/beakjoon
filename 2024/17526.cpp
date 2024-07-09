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

int s[100010], p[100010], dist[100010];
ll psum[100010], dp[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<N; i++) cin >> dist[i];
    for(int i=2; i<=N; i++) psum[i] += psum[i-1] + dist[i-1];
    for(int i=1; i<N; i++) cin >> p[i] >> s[i];
    
    lichao.init();
    for(int i=1; i<N; i++){
        lichao.update(0, 0, 1e9, {-s[i], psum[i] * s[i] - dp[i] - p[i]});
        dp[i+1] = -lichao.query(0, 0, 1e9, psum[i+1]);
    }
    cout << dp[N] << '\n';

    return 0;
}