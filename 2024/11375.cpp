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
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    HopcroftKarp bp(N, M);
    for(int i=0; i<N; i++){
        int k; cin >> k;
        for(int j=0; j<k; j++){
            int v; cin >> v;
            bp.addEdge(i, v - 1);
        }
    }
    cout << bp.maximum_matching() << '\n';

    return 0;
}