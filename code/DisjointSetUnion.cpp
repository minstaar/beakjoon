#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent;

    void init(int n){
        parent = vector<int>(n+1, -1);
    }

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        x = Find(x), y = Find(y);
        if(x == y) return false;
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
}UF;