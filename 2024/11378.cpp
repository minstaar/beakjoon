#include <bits/stdc++.h>
using namespace std;

struct Dinic{
    struct Edge{
        int next, dual, spare;
    };
    const int INF = 1e9;
    int n, S, T;
    vector<int> level, work;
    vector<vector<Edge>> adj;

    void init(int _n, int _S, int _T){
        n = _n, S = _S, T = _T;
        adj = vector<vector<Edge>>(n+1);
    }

    void addEdge(int u, int v, int w, bool directed = 1){
        Edge e1 = {v, adj[v].size(), w}, e2 = {u, adj[u].size(), (directed ? 0 : w)};
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    bool bfs(){
        level = vector<int>(n+1, -1);
        level[S] = 0;
        queue<int> que;
        que.push(S);
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto [next, dual, spare]: adj[cur]){
                if(level[next] == -1 && spare > 0){
                    level[next] = level[cur] + 1;
                    que.push(next);
                }
            }
        }
        return level[T] != -1;
    }

    int dfs(int cur, int flow){
        if(cur == T) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            auto &[next, dual, spare] = adj[cur][i];
            if(level[next] == level[cur] + 1 && spare > 0){
                int df = dfs(next, min(spare, flow));
                if(df > 0){
                    spare -= df;
                    adj[next][dual].spare += df;
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
                int flow = dfs(S, INF);
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

    int N, M, K; cin >> N >> M >> K;
    int S = N + M + 1, T = N + M + 3;
    int B = N + M + 2;
    nf.init(N + M + 3, S, T);
    nf.addEdge(S, B, K);
    for(int i=1; i<=N; i++){
        nf.addEdge(S, i, 1);
        nf.addEdge(B, i, K);
    }
    for(int i=1; i<=M; i++){
        nf.addEdge(i + N, T, 1);
    }
    for(int i=1; i<=N; i++){
        int k; cin >> k;
        for(int j=0; j<k; j++){
            int v; cin >> v;
            nf.addEdge(i, v + N, 1);
        }
    }

    cout << nf.get_maxflow() << '\n';

    return 0;
}