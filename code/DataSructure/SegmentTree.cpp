#include <bits/stdc++.h>
using namespace std;

template<typename node_t> struct SegmentTree{
    vector<int> arr;
    vector<node_t> tree;
    
    void Init(int n){
        arr = vector<int>(n);
        tree = vector<node_t>(1<<((int)ceil(log2(n))+1));
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

    void update(int node, int s, int e, int idx, node_t val){
        if(idx < s || e > idx) return;
        tree[node] += val;
        if(s != e){
            int m = s + e >> 1;
            update(node * 2, s, m, idx, val), update(node * 2 + 1, m + 1, e, idx, val);
        }
    }

    node_t query(int node, int s, int e, int l, int r){
        if(l > e || r < s) return 0;
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        return Merge(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }
};