#include <bits/stdc++.h>
using namespace std;

struct CentroidTree{
    vector<int> sz, parent;
    vector<vector<int>> adj;
    vector<bool> visited;

    CentroidTree(int n): sz(n), adj(n), visited(n), parent(n) {}

    int getSize(int prev, int cur){
        sz[cur] = 1;
        for(auto next: adj[cur]){
            if(next != prev && !visited[next]){
                sz[cur] += getSize(cur, next);
            }
        }
        return sz[cur];
    }

    int getCent(int prev, int cur, int cnt){
        for(auto next: adj[cur]){
            if(next != prev && !visited[next] && sz[next] * 2 > cnt){
                return getCent(cur, next, cnt);
            }
        }
        return cur;
    }

    void init(int prev, int cur){
        int cent = getCent(prev, cur, getSize(prev, cur));
        visited[cent] = true;
        parent[cent] = (prev == -1 ? cent : prev);
        for(auto next: adj[cent]){
            if(!visited[next]) init(cent, next);
        }
    }
};