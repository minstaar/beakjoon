#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp{
    int n, m;
    vector<vector<int>> adj;
    vector<int> dist, l, r;
    vector<char> visit, track;

    HopcroftKarp(int _n, int _m): n(_n), m(_m), adj(_n), dist(_n), l(_n, -1), r(_m, -1), visit(_n), track(_n) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    bool bfs(){
        bool res = false;
        queue<int> que;
        fill(dist.begin(), dist.end(), 0);
        for(int i=0; i<n; i++){
            if(l[i] == -1){
                que.push(i);
                dist[i] = 1;
            }
        }
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto i: adj[v]){
                if(r[i] == -1) res = true;
                else if(!dist[r[i]]){
                    dist[r[i]] = dist[v] + 1;
                    que.push(r[i]);
                }
            }
        }
        return res;
    }

    bool dfs(int v){
        if(visit[v]) return false;
        visit[v] = 1;
        for(auto i: adj[v]){
            if(r[i] == -1 || !visit[r[i]] && dist[r[i]] == dist[v] + 1 && dfs(r[i])){
                l[v] = i, r[i] = v;
                return true;
            }
        }
        return false;
    }

    int maximum_matching(){
        int res = 0;
        fill(l.begin(), l.end(), -1);
        fill(r.begin(), r.end(), -1);
        while(bfs()){
            fill(visit.begin(), visit.end(), 0);
            for(int i=0; i<n; i++){
                if(l[i] == -1) res += dfs(i);
            }
        }
        return res;
    }

    vector<pair<int,int>> maximum_matching_edges(){
        int matching = maximum_matching();
        vector<pair<int,int>> edges;
        edges.reserve(matching);
        for(int i=0; i<n; i++) if(l[i] != -1) edges.emplace_back(i, l[i]);
        return edges;
    }

    void dfs_track(int v){
        if(track[v]) return; track[v] = 1;
        for(auto i: adj[v]){
            track[n+i] = 1;
            dfs_track(r[i]);
        }
    }

    tuple<vector<int>, vector<int>, int> minimum_vertex_cover(){
        int matching = maximum_matching();
        vector<int> lv, rv;
        fill(track.begin(), track.end(), 0);
        for(int i=0; i<n; i++) if(l[i] == -1) dfs_track(i);
        for(int i=0; i<n; i++) if(!track[i]) lv.push_back(i);
        for(int i=0; i<m; i++) if(track[n+i]) rv.push_back(i);
        return {lv, rv, lv.size() + rv.size()}; // s(lv)+s(rv)=mat
    }

    tuple<vector<int>, vector<int>, int> maximum_independent_set(){
        auto [a, b, matching] = minimum_vertex_cover();
        vector<int> lv, rv;
        lv.reserve(n - a.size());
        rv.reserve(m - b.size());
        for(int i=0, j=0; i<n; i++){
            while(j < a.size() && a[j] < i) j++;
            if(j == a.size() || a[j] != i) lv.push_back(i);
        }
        for(int i=0, j=0; i<m; i++){
            while(j < b.size() && b[j] < i) j++;
            if(j == b.size() || b[j] != i) rv.push_back(i);
        } // s(lv)+s(rv)=n+m-mat
        return {lv, rv, lv.size() + rv.size()};
    }

    vector<vector<int>> minimum_path_cover(){ // n == m
        int matching = maximum_matching();
        vector<vector<int>> res;
        res.reserve(n - matching);
        fill(track.begin(), track.end(), 0);
        auto get_path = [&](int v) -> vector<int> {
            vector<int> path{v}; // ri[v] == -1
            while(l[v] != -1) path.push_back(v=l[v]);
            return path;
        };
        for(int i=0; i<n; i++){
            if(!track[n+i] && r[i] == -1){
                res.push_back(get_path(i));
            }
        }
        return res; // sz(res) = n-mat
    }

    vector<int> maximum_anti_chain(){ // n = m
        auto [a, b, matching] = minimum_vertex_cover();
        vector<int> res;
        res.reserve(n - a.size() - b.size());
        for(int i=0, j=0, k=0; i<n; i++){
            while(j < a.size() && a[j] < i) j++;
            while(k < b.size() && b[k] < i) k++;
            if((j == a.size() || a[j] != i) && (k == b.size() || b[k] != i)){
                res.push_back(i);
            }
        }
        return res; // sz(res) = n-mat
    }
};