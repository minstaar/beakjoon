#include <bits/stdc++.h>
using namespace std;

template<class flow_t> struct Dinic{
    const flow_t INF = numeric_limits<flow_t>::max() / 2;
    int n;
    vector<int> level, work;
    vector<vector<flow_t>> adj;
    vector<vector<flow_t>> c, f;

    Dinic(int _n): n(_n), adj(_n), c(_n, vector<int>(_n)), f(_n, vector<int>(_n)) {}
    
    void addEdge(int u, int v, flow_t w, flow_t recap = 0){
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += w;
        c[v][u] += recap;
    }

    bool bfs(int S, int T){
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

    flow_t dfs(int cur, int T, flow_t flow){
        if(cur == T) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0){
                flow_t df = dfs(next, T, min(c[cur][next] - f[cur][next], flow));
                if(df > 0){
                    f[cur][next] += df;
                    f[next][cur] -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    flow_t get_maxflow(int S, int T){
        flow_t total = 0;
        while(bfs(S, T)){
            work = vector<int>(n+1, 0);
            while(1){
                flow_t flow = dfs(S, T, INF);
                if(flow == 0) break;
                total += flow;
            }
        }
        return total;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        int S = 0, T = N - 1;
        Dinic<int> nf(N);
        for(int i=0; i<M; i++){
            int u, v, w; cin >> u >> v >> w;
            nf.addEdge(u - 1, v - 1, w);
        }
        nf.get_maxflow(S, T);

        int res = 0;
        queue<int> que;
        vector<int> level(N, -1);
        que.push(S);
        level[S] = 0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto v: nf.adj[u]){
                if(nf.c[u][v] == nf.f[u][v]){
                    queue<int> que2;
                    vector<int> prev(N, -1);
                    que2.push(u);
                    while(!que2.empty()){
                        int cur = que2.front();
                        que2.pop();
                        if(prev[v] != -1) break;
                        for(auto next: nf.adj[cur]){
                            if(prev[next] == -1 && nf.c[cur][next] - nf.f[cur][next] > 0){
                                que2.push(next);
                                prev[next] = cur;
                            }
                        }
                    }
                    if(prev[v] != -1) res++;
                }
                if(level[v] == -1){
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}