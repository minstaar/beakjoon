#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    struct Node{
        int l, r, sum;
        Node() {l = -1, r = -1, sum = 0;}
    };
    vector<Node> tree;
    int pv;

    void Init(int n){
        tree = vector<Node>(n*4);
        pv = 1;
    }

    void update(int node, int s, int e, int idx, int val){
        if(s == e){
            tree[node].sum = val;
            return;
        }
        int m = s + e >> 1;
        if(idx <= m){
            if(tree[node].l == -1) tree[node].l = pv++;
            update(tree[node].l, s, m, idx, val);
        }
        else{
            if(tree[node].r == -1) tree[node].r = pv++;
            update(tree[node].r, m + 1, e, idx, val);
        }
        int a = tree[node].l != -1 ? tree[tree[node].l].sum : 0;
        int b = tree[node].r != -1 ? tree[tree[node].r].sum : 0;
        tree[node].sum = a + b;
    }

    int query(int node, int s, int e, int l, int r){
        if(node == -1) return 0;
        if(l > e || r < s) return 0;
        if(l <= s && e <= r) return tree[node].sum;
        int m = s + e >> 1;
        return query(tree[node].l, s, m, l, r) + query(tree[node].r, m + 1, e, l, r);
    }
}Seg;