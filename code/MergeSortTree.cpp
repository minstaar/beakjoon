#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

struct MergeSortTree{
    int sz;
    vector<vector<int>> tree;
    
    void Init(int n){
        for(sz=1; sz<n; sz++);
        tree = vector<vector<int>>(sz<<1);
    }
    
    void add(int x, int v){
        --x |= sz;
        tree[x].push_back(v);
    }

    void construct(){
        for(int i=sz-1; i>0; i--){
            tree[i].resize(tree[i<<1].size() + tree[i<<1|1].size());
            merge(all(tree[i<<1]), all(tree[i<<1|1]), tree[i].begin());
        }
    }
    
    int query(int l, int r, int k){
        --l |= sz, --r |= sz;
        int res = 0;
        while(l <= r){
            if(l & 1){
                res += upper_bound(all(tree[l]), k) - tree[l].begin();
                l++;
            }
            if(~r & 1){
                res += upper_bound(all(tree[r]), k) - tree[r].begin();
                r--;
            }
            l >>= 1, r >>= 1;
        }
        return res;
    }
}Seg;