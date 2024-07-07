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