#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const ld INF = 1e16;
const ld EPS = 1e-8;

struct LiChaoTree{
    struct Line{
        ld m, b;
        int idx;
        ld f(ld x) {return m * x + b;}
        Line(ld m, ld b, int idx): m(m), b(b), idx(idx) {}
        Line(): Line(0, INF, 0) {}
    };
    struct Node{
        int l, r; Line line;
        Node(): l(-1), r(-1), line(0, INF, 0) {}
    };

    vector<Node> tree;

    void init(){
        tree.emplace_back();
    }

    void update(int node, ld s, ld e, Line v){
        Line lo = tree[node].line, hi = v;
        if(lo.f(s) > hi.f(s)) swap(lo, hi);
        if(lo.f(e) < hi.f(e) || abs(lo.f(e) - hi.f(e)) < EPS){
            tree[node].line = lo;
            return;
        }
        ld m = (s + e) / 2.0;
        if(lo.f(m) < hi.f(m) || abs(lo.f(m) - hi.f(m)) < EPS && lo.m < hi.m || abs(lo.f(m) - hi.f(m)) < EPS && abs(lo.m - hi.m) < EPS && lo.b < hi.b){
            tree[node].line = lo;
            if(tree[node].r == -1){
                tree[node].r = tree.size();
                tree.emplace_back();
            }
            update(tree[node].r, m + EPS, e, hi);
        }
        else{
            tree[node].line = hi;
            if(tree[node].l == -1){
                tree[node].l = tree.size();
                tree.emplace_back();
            }
            update(tree[node].l, s, m, lo);
        }
    }

    Line query(int node, ld s, ld e, ld x){
        if(node == -1) return {0, INF, -1};
        Line t = tree[node].line, cmp;
        ld m = (s + e) / 2.0;
        if(x < m || (abs(x - m) < EPS)) cmp = query(tree[node].l, s, m, x);
        else cmp = query(tree[node].r, m + EPS, e, x);
        if(abs(t.f(x) - cmp.f(x)) < EPS){
            if(abs(t.m - cmp.m) < EPS && t.b < cmp.b || t.m < cmp.m) return t;
            else return cmp;
        }
        if(t.f(x) < cmp.f(x)) return t;
        else return cmp;
    }
}lichao;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int s, e; cin >> e >> s;
    lichao.init();
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        ld y1, y2; cin >> y2 >> y1;
        ld m = (y2 - y1) / (e - s);
        lichao.update(0, s, e, {m, y1 - m * s, i});
    }
    int Q; cin >> Q;
    while(Q--){
        ld x; cin >> x;
        cout << lichao.query(0, s, e, x).idx << '\n';
    }

    return 0;
}