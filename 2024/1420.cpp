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

    int getflow(int v, int e){
        return adj[v][e].spare;
    }

    bool cutSide(int v){
        return level[v] != -1;
    }
}nf;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    int S = -1, T = -1;
    int pv = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'K') S = pv + N * M;
            else if(arr[i][j] == 'H') T = pv;
            pv++;
        }
    }

    if(N == 1 && M == 1 || S == -1 || T == -1){
        cout << -1 << '\n';
    }
    else{
        nf.init(N * M * 2, S, T);
        pv = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] != '#'){
                    nf.addEdge(pv, pv + N * M, 1);
                    if(i + 1 < N && arr[i+1][j] != '#'){
                        nf.addEdge(pv + N * M, pv + M, 1e9);
                        nf.addEdge(pv + N * M + M, pv, 1e9);
                    }
                    if(j + 1 < M && arr[i][j+1] != '#'){
                        nf.addEdge(pv + N * M, pv + 1, 1e9);
                        nf.addEdge(pv + N * M + 1, pv, 1e9);
                    }
                }
                pv++;
            }
        }

        int flow = nf.get_maxflow();
        if(flow >= nf.INF) cout << -1 << '\n';
        else cout << flow << '\n';
    }

    return 0;
}