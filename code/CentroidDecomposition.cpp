#include <bits/stdc++.h>
using namespace std;

struct CentroidTree{
    vector<int> sz, parent;
    vector<bool> visited;

    CentroidTree(int n): sz(n), visited(n), parent(n) {}

    int getSize(vector<vector<int>> adj, int prev, int cur){
        sz[cur] = 1;
        for(auto next: adj[cur]){
            if(next != prev && !visited[next]){
                sz[cur] += getSize(adj, cur, next);
            }
        }
        return sz[cur];
    }

    int getCent(vector<vector<int>> adj, int prev, int cur, int cnt){
        for(auto next: adj[cur]){
            if(next != prev && !visited[next] && sz[next] * 2 > cnt){
                return getCent(adj, cur, next, cnt);
            }
        }
        return cur;
    }

    void init(vector<vector<int>> adj, int prev, int cur){
        int cent = getCent(adj, prev, cur, getSize(adj, prev, cur));
        visited[cent] = true;
        parent[cent] = prev;
        for(auto next: adj[cent]){
            if(!visited[next]) init(adj, cent, next);
        }
    }
};