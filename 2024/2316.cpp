#include <bits/stdc++.h>
using namespace std;

struct Dinic{
    const int INF = 1e9;
    int n, S, T;
    vector<int> level, work;
    vector<vector<int>> adj, c, f;

    void init(int _n, int _S, int _T){
        n = _n, S = _S, T = _T;
        adj = vector<vector<int>>(n+1);
        c = vector<vector<int>>(n+1, vector<int>(n+1));
        f = vector<vector<int>> (n+1, vector<int>(n+1));
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] = w;
    }

    bool bfs(){
        level = vector<int>(n+1, -1);
        level[S] = 0;
        queue<int> que;
        que.push(S);
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto next: adj[cur]){
                if(level[next] == -1 && c[cur][next] - f[cur][next] > 0){
                    level[next] = level[cur] + 1;
                    que.push(next);
                }
            }
        }
        return level[T] != -1;
    }

    int dfs(int cur, int dest, int flow){
        if(cur == dest) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0){
                int df = dfs(next, dest, min(c[cur][next] - f[cur][next], flow));
                if(df > 0){
                    f[cur][next] += df;
                    f[next][cur] -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    int get_maxflow(){
        int total = 0;
        while(bfs()){
            work = vector<int>(n+1);
            while(1){
                int flow = dfs(S, T, INF);
                if(flow == 0) break;
                total += flow;
            }
        }
        return total;
    }
}nf;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V, E; cin >> V >> E;
    int source = 1 + V, sink = 2;
    nf.init(V * 2, source, sink);
    for(int i=1; i<=V; i++){
        nf.addEdge(i, i + V, 1);
    }
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        nf.addEdge(v + V, u, 1);
        nf.addEdge(u + V, v, 1);
    }

    cout << nf.get_maxflow() << '\n';

    return 0;
}