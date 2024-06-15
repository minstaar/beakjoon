#include <bits/stdc++.h>
using namespace std;

struct Dinic{
    const int INF = 1e9;
    int n, S, T;
    vector<int> level, work;
    vector<vector<int>> adj;
    vector<vector<int>> c, f;

    void init(int _n, int _S, int _T){
        n = _n, S = _S, T = _T;
        adj = vector<vector<int>>(n + 1);
        c = f = vector<vector<int>>(n + 1, vector<int>(n + 1));
    }

    void addEdge(int u, int v, int w, bool directed = 1){
        c[u][v] = w, c[v][u] = directed ? 0 : w;
        adj[u].push_back(v);
        adj[v].push_back(u);
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

    int dfs(int cur, int flow){
        if(cur == T) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0){
                int df = dfs(next, min(c[cur][next] - f[cur][next], flow));
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
        f = vector<vector<int>>(n+1, vector<int>(n+1, 0));
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

bool check(int N, int x, int comp)
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            nf.c[i][j+N] = x;
        }
    }
    return comp == nf.get_maxflow();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> row(N), col(N);
    int S = 2 * N, T = 2 * N + 1;
    int sum = 0;
    nf.init(N * 2 + 1, S, T);
    for(int i=0; i<N; i++){
        cin >> row[i];
        nf.addEdge(S, i, row[i]);
        sum += row[i];
    }
    for(int i=0; i<N; i++){
        cin >> col[i];
        nf.addEdge(i + N, T, col[i]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            nf.addEdge(i, j + N, 0);
        }
    }

    int l = 0, r = 10000;
    int ans = 0;
    while(l <= r){
        int m = l + r >> 1;
        if(check(N, m, sum)){
            ans = m, r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans << '\n';
    check(N, ans, sum);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << nf.f[i][j+N] << ' ';
        }
        cout << '\n';
    }


    return 0;
}