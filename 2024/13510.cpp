#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int sz;
    vector<int> tree;
    
    void init(int n){
        for(sz=1; sz<n; sz<<=1);
        tree = vector<int>(sz<<1);
    }

    void add(int x, int val){
        --x |= sz;
        tree[x] = val;
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void update(int i, int val){
        --i |= sz;
        tree[i] = val;
        while(i >>= 1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    int query(int l, int r){
        --l |= sz, --r |= sz;
        int res1 = 0, res2 = 0;
        while(l <= r){
            if(l & 1) res1 = tree[l++];
            if(~r & 1) res2 = tree[r--];
            l >>= 1, r >>= 1;
        }
        return max(res1, res2);
    }
};