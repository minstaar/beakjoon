#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent;

    UnionFind(int n): parent(n+1, -1) {}

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        x = Find(x), y = Find(y);
        if(x != y){
            parent[x] += parent[y];
            parent[y] = x;
            return true;
        }
        return false;
    }
};