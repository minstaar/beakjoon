#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V = 410;
const int INF = 1e9 + 7;

struct Edge
{
    int to, c, f;
    Edge *dual;
    Edge(int _to, int _c): to(_to), c(_c), f(0), dual(nullptr) {}
    int spare()
    {
        return c - f;
    }
    void addFlow(int f1)
    {
        f += f1;
        dual->f -= f1;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V, E; cin >> V >> E;
    vector<Edge*> adj[V+1];
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        Edge *e1 = new Edge(v, 1), *e2 = new Edge(u, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    int total = 0;
    while(1){
        int prev[MAX_V];
        Edge *path[MAX_V] = {0};
        fill(prev, prev+MAX_V, -1);
        queue<int> que;
        que.push(1);
        while(!que.empty() && prev[2] == -1){
            int cur = que.front();
            que.pop();
            for(Edge *e: adj[cur]){
                int next = e->to;
                if(e->spare() > 0 && prev[next] == -1){
                    que.push(next);
                    prev[next] = cur;
                    path[next] = e;
                    if(next == 2) break;
                }
            }
        }
        if(prev[2] == -1) break;
        int flow = INF;
        for(int i=2; i!=1; i=prev[i]){
            flow = min(flow, path[i]->spare());
        }
        for(int i=2; i!=1; i=prev[i]){
            path[i]->addFlow(flow);
        }
        total += flow;
    }
    cout << total << '\n';

    return 0;
}