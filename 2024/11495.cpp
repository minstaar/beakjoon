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

    Dinic(int _n): n(_n), adj(n+1) {}
    
    void setS(int _S) {S = _S;}
    void setT(int _T) {T = _T;}

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
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        Dinic nf(N * M + 2);
        vector<vector<int>> arr(N+1, vector<int>(M+1));
        int S = 0; nf.setS(S);
        int T = N * M + 1; nf.setT(T);
        int pv = 1, sum = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cin >> arr[i][j];
                if((i + j) % 2){
                    nf.addEdge(S, pv, arr[i][j]);
                }
                else{
                    nf.addEdge(pv, T, arr[i][j]);
                }
                sum += arr[i][j];
                pv++;
            }
        }
        pv = 1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if((i + j) % 2){
                    int dy[4] = {-1, 1, 0, 0};
                    int dx[4] = {0, 0, -1, 1};
                    int dp[4] = {-M, M, -1, 1};
                    for(int k=0; k<4; k++){
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
                        nf.addEdge(pv, pv + dp[k], 1e9);
                    }
                }
                pv++;
            }
        }
        cout << sum - nf.get_maxflow() << '\n';
    }

    return 0;
}