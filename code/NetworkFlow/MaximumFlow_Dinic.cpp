#include <bits/stdc++.h>
using namespace std;

template<class flow_t> struct Dinic{
    struct Edge{
        int next, dual;
        flow_t spare;
    };
    const flow_t INF = numeric_limits<flow_t>::max() / 2;
    int n;
    vector<int> level, work;
    vector<vector<Edge>> adj;

    Dinic(int _n): n(_n), adj(_n) {}
    
    void addEdge(int u, int v, flow_t cap, flow_t recap = 0){
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, recap});
    }

    bool bfs(int S, int T){
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

    flow_t dfs(int cur, int T, flow_t flow){
        if(cur == T) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            auto &[next, dual, spare] = adj[cur][i];
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
};