#include <bits/stdc++.h>
using namespace std;

template<class flow_t> struct Dinic{
    struct Edge{
        int next, dual;
        flow_t spare, cap;
    };
    const flow_t INF = numeric_limits<flow_t>::max() / 2;
    int n;
    vector<int> level, work;
    vector<vector<Edge>> adj;

    Dinic(int _n): n(_n), adj(_n) {}
    
    void addEdge(int u, int v, flow_t cap, flow_t recap = 0){
        adj[u].push_back({v, (int)adj[v].size(), cap, cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, recap, cap});
    }

    bool bfs(int S, int T){
        level = vector<int>(n+1, -1);
        level[S] = 0;
        queue<int> que;
        que.push(S);
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto [next, dual, spare, cap]: adj[cur]){
                if(level[next] == -1 && spare > 0){
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
            auto &[next, dual, spare, cap] = adj[cur][i];
            if(level[next] == level[cur] + 1 && spare > 0){
                flow_t df = dfs(next, T, min(spare, flow));
                if(df > 0){
                    spare -= df;
                    adj[next][dual].spare += df;
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

    flow_t getflow(int v, int e){
        return adj[v][e].spare;
    }

    bool cutSide(int v){
        return level[v] != -1;
    }

    void changeFlow(int v, int e){
        int S = v, T = adj[v][e].next;
        vector<int> prev(n, -1), path(n);
        queue<int> que;
        que.push(S);
        while(!que.empty() && prev[T] == -1){
            int cur = que.front();
            que.pop();
            for(int i=0; i<adj[cur].size(); i++){
                auto [next, dual, spare, cap] = adj[cur][i];
                if(cur < S || cur == S && next < T) continue;
                if(spare && prev[next] == -1){
                    prev[next] = cur;
                    path[next] = i;
                    if(next == T) break;
                    que.push(next);
                }
            }
        }
        if(prev[T] == -1) return;
        auto &i = adj[v][e];
        i.spare = 1;
        adj[i.next][i.dual].spare = 1;
        for(int i=T; i!=S; i=prev[i]){
            auto &[next, dual, spare, cap] = adj[prev[i]][path[i]];
            spare -= 1, adj[next][dual].spare += 1;
        }
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    int S = 0, T = N + M + 1;
    Dinic<int> nf(110);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            nf.addEdge(i, j + N, 1);
        }
    }
    int sum1 = 0, sum2 = 0;
    for(int i=1; i<=N; i++){
        int c; cin >> c;
        sum1 += c;
        nf.addEdge(S, i, c);
    }
    for(int i=1; i<=M; i++){
        int c; cin >> c;
        sum2 += c;
        nf.addEdge(i + N, T, c);
    }
    
    int mx = nf.get_maxflow(S, T);
    if(mx != sum1 || mx != sum2 || sum1 != sum2) cout << -1 << '\n';
    else{
        for(int i=1; i<=N; i++){
            for(int j=0; j<M; j++){
                if(nf.adj[i][j].cap && !nf.adj[i][j].spare){
                    nf.changeFlow(i, j);
                }
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=0; j<M; j++){
                cout << !nf.getflow(i, j);
            }
            cout << '\n';
        }
    }

    return 0;
}