#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int S, T;
vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX];

void addEdge(int u, int v, int cap, int recap)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] = cap;
    c[v][u] = recap;
}

int get_maxflow()
{
    int total = 0;
    while(1){
        vector<int> prev(MAX, -1);
        queue<int> que;
        que.push(S);
        while(!que.empty() && prev[T] == -1){
            int cur = que.front();
            que.pop();
            for(auto next: adj[cur]){
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1){
                    prev[next] = cur;
                    que.push(next);
                    if(next == T) break;
                }
            }
        }
        if(prev[T] == -1) break;
        int flow = 1e9;
        for(int i=T; i!=S; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i=T; i!=S; i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }
    return total;
}