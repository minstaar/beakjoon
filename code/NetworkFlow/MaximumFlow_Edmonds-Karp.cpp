#include <bits/stdc++.h>
using namespace std;

struct MaximumFlow{
    struct Edge{
        int to, c, f;
        Edge *dual;
        Edge(int _to, int _c): to(_to), c(_c), f(0), dual(nullptr){}
        int spare(){
            return c - f;
        }
        void addFlow(int f1){
            f += f1;
            dual-> f -= f1;
        }
    };

    int n, S, T;
    vector<vector<Edge*>> adj;

    void init(int _n, int _S, int _T){
        n = _n, S = _S, T = _T;
        adj = vector<vector<Edge*>>(n+1);
    }

    void addEdge(int u, int v, int w){
        Edge *e1 = new Edge(v, w), *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    int get_maxflow(){
        int total = 0;
        vector<int> prev;
        vector<Edge*> path;    
        while(1){
            prev = vector<int>(n+1, -1);
            path = vector<Edge*>(n+1);
            queue<int> que;
            que.push(S);
            while(!que.empty() && prev[T] == -1){
                int cur = que.front();
                que.pop();
                for(Edge *e: adj[cur]){
                    int next = e->to;
                    if(e->spare() > 0 && prev[next] == -1){
                        que.push(next);
                        prev[next] = cur;
                        path[next] = e;
                        if(next == T) break;
                    }
                }
            }
            if(prev[T] == -1) break;
            int flow = 1e9;
            for(int i=T; i!=S; i=prev[i]){
                flow = min(flow, path[i]->spare());
            }
            for(int i=T; i!=S; i=prev[i]){
                path[i]->addFlow(flow);
            }
            total += flow;
        }
        return total;
    }
};

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int next, inv, c, f;
    int spare(){
        return c - f;
    }
};

const int MAX = 1010;
int N, arr[2][510];
int S, T;
vector<Edge> adj[MAX];
vector<int>

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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    S = 0, T = 2 * N + 1;
    for(int i=1; i<=N; i++){
        addEdge(S, i, arr[0][i], 0);
        addEdge(i, T, arr[1][i], 0);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            addEdge(i, j + N, 1, 0);
        }
    }
    
    get_maxflow();

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][])
        }
    }
}