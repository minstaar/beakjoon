#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int next, inv, c, f;
    int spare(){
        return c - f;
    }
};

const int MAX = 1010;
int S, T;
vector<Edge> adj[MAX];

void addEdge(int u, int v, int cap, int recap)
{
    adj[u].push_back({v, (int)adj[v].size(), cap, 0});
    adj[v].push_back({u, (int)adj[u].size() - 1, recap, 0});
}

int get_maxflow()
{
    int total = 0;
    while(1){
        vector<int> prev(MAX, -1), path(MAX);
        queue<int> que;
        que.push(S);
        while(!que.empty() && prev[T] == -1){
            int cur = que.front();
            que.pop();
            for(int i=0; i<adj[i].size(); i++){
                auto [next, inv, c, f] = adj[cur][i];
                if(c - f > 0 && prev[next] == -1){
                    prev[next] = cur;
                    path[next] = i;
                    que.push(next);
                    if(next == T) break;
                }
            }
        }
        if(prev[T] == -1) break;
        int flow = 1e9;
        for(int i=T; i!=S; i=prev[i]) flow = min(flow, adj[prev[i]][path[i]].spare());
        for(int i=T; i!=S; i=prev[i]){
            auto &[next, inv, c, f] = adj[prev[i]][path[i]];
            f += flow;
            adj[next][inv].f -= flow;
        }
        total += flow;
    }
    return total;
}