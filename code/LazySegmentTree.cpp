#include <bits/stdc++.h>
using namespace std;

template<typename node_t> struct SegmentTree{
    vector<int> arr;
    vector<node_t> tree, lazy;
    
    void Init(int n){
        arr = vector<int>(n);
        tree = lazy = vector<node_t>(1<<((int)ceil(log2(n))+1));
    }

    node_t Merge(node_t l, node_t r){
        return l + r;
    }

    void init(int node, int s, int e){
        if(s == e){
            tree[node] = arr[s];
            return;
        }
        int m = s + e >> 1;
        init(node * 2, s, m), init(node * 2 + 1, m + 1, e);
        tree[node] = Merge(tree[node*2], tree[node*2+1]);
    }

    void propagate(int node, int s, int e){
        if(!lazy[node]) return;
        tree[node] += lazy[node];
        if(s != e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update_range(int node, int s, int e, int l, int r, node_t val){
        propagate(node, s, e);
        if(l > e || r < s) return;
        if(l <= s && e <= r){
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update_range(node * 2, s, m, l, r, val), update_range(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = Merge(tree[node*2], tree[node*2+1]);
    }

    node_t query(int node, int s, int e, int l, int r){
        propagate(node, s, e);
        if(l > e || r < s) return 0;
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        return Merge(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }
};