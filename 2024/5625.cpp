#include <bits/stdc++.h>
using namespace std;

template<typename node_t> struct SegmentTree{
    int sz;
    vector<node_t> tree;
    
    SegmentTree(int n){
        for(sz=1; sz<n; sz<<=1);
        tree = vector<node_t>(sz<<1);
    }

    void add(int x, node_t val){
        --x |= sz;
        tree[x] = val;
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void update(int i, node_t val){
        i |= sz;
        tree[i] += val;
        while(i >>= 1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    node_t get(int x){
        --x |= sz;
        return tree[x];
    }

    node_t query(int l, int r){
        l |= sz, r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 += tree[l++];
            if(~r & 1) res2 += tree[r--];
            l >>= 1, r >>= 1;
        }
        return res1 + res2;
    }
};
SegmentTree<int> startX(1000010), startY(1000010), endX(1000010), endY(1000010);



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int t = min({x1, x2, x3});
        startX.update(t, 1);
        t = max({x1, x2, x3});
        endX.update(t, 1);
        t = min({y1, y2, y3});
        startY.update(t, 1);
        t = max({y1, y2, y3});
        endY.update(t, 1);
    }

    int Q; cin >> Q;
    while(Q--){
        char op, t; int p; cin >> op >> t >> p;
        if(op == 'x'){
            int left = endX.query(0, p);
            int right = startX.query(p, 1000000);
            cout << N - left - right << '\n';
        }
        else{
            int left = endY.query(0, p);
            int right = startY.query(p, 1000000);
            cout << N - left - right << '\n';
        }
    }

    return 0;
}