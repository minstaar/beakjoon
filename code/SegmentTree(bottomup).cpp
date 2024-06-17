#include <bits/stdc++.h>
using namespace std;

template<typename node_t> struct SegmentTree{
    int sz;
    vector<node_t> tree;
    
    void init(int n){
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
        --i |= sz;
        tree[i] = val;
        while(i >>= 1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    int query(int x){
        --x |= sz;
        return tree[x];
    }

    node_t query(int l, int r){
        --l |= sz, --r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 = tree[l++];
            if(~r & 1) res2 = tree[r--];
            l >>= 1, r >>= 1;
        }
        return res1 + res2;
    }
};