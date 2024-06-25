#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct MCMF{
    const int INF = 1e9;
    int n;
    vector<vector<int>> adj, c, f, d;

    MCMF(int n): n(n), adj(n), c(n, vector<int>(n)), f(n, vector<int>(n)), d(n, vector<int>(n)) {}

    void addEdge(int u, int v, int cap, int cost){
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = cap, d[u][v] = cost;
        d[v][u] = -cost;
    }

    pii get_MCMF(int S, int T){
        pii res; //{cost, flow}
        while(1){
            vector<int> prev(n, -1), dist(n, INF);
            vector<bool> inQue(n);
            queue<int> que; que.push(S); dist[S] = 0; inQue[S] = true;
            while(!que.empty()){
                int cur = que.front(); que.pop(); inQue[cur] = false;
                for(auto next: adj[cur]){
                    if(c[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]){
                        dist[next] = dist[cur] + d[cur][next];
                        prev[next] = cur;
                        if(!inQue[next]){que.push(next); inQue[next] = true;}
                    }
                }
            }
            if(prev[T] == -1) break;

            int flow = INF;
            for(int i=T; i!=S; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
            for(int i=T; i!=S; i=prev[i]){
                f[prev[i]][i] += flow, f[i][prev[i]] -= flow;
            }
            res.first += flow * dist[T];
            res.second += flow;
        }
        return res;
    }
};