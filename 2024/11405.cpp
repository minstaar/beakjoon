#include <bits/stdc++.h>
using namespace std;

template<typename flow_t, typename cost_t, int sz>
struct MCMF{
    struct Edge{int v, dual; flow_t c; cost_t d;};
    vector<Edge> adj[sz];
    flow_t flow_max = numeric_limits<flow_t>::max() / 2;
    cost_t cost_max = numeric_limits<cost_t>::max() / 2;

    void addEdge(int s, int e, flow_t c, cost_t d){
        adj[s].push_back({e, (int)adj[e].size(), c, d});
        adj[e].push_back({s, (int)adj[s].size() - 1, 0, -d});
    }

    int inQue[sz];
    cost_t h[sz], dist[sz];
    void init(int S, int T){
        fill(h, h + sz, cost_max);
        fill(dist, dist + sz, cost_max);
        queue<int> que; que.push(S); inQue[S] = 1;
        while(!que.empty()){
            int cur = que.front(); que.pop(); inQue[cur] = 0;
            for(auto i: adj[cur]){
                if(i.c && h[i.v] > h[cur] + i.d){
                    h[i.v] = h[cur] + i.d;
                    if(!inQue[i.v]){
                        inQue[i.v] = 1;
                        que.push(i.v);
                    }
                }
            }
        }
        for(int i=0; i<sz; i++){
            for(auto &j : adj[i]){
                if(j.c) j.d += h[i] - h[j.v];
            }
        }
        priority_queue<pair<cost_t, int>> pq; pq.push({0, S}); dist[S] = 0;
        while(!pq.empty()){
            int cur = pq.top().second;
            cost_t cost = -pq.top().first;
            pq.pop();
            if(dist[cur] != cost) continue;
            for(auto i: adj[cur]){
                if(i.c && dist[i.v] > dist[cur] + i.d){
                    dist[i.v] = dist[cur] + i.d;
                    pq.push({-dist[i.v], i.v});
                }
            }
        }
        for(int i=0; i<sz; i++) dist[i] += h[T] - h[S];
    }

    int chk[sz], work[sz];
    bool update(){
        cost_t mn = cost_max;
        for(int i=0; i<sz; i++) if(chk[i]){
            for(auto j: adj[i]) if(j.c && !chk[j.v]){
                mn = min(mn, dist[i] + j.d - dist[j.v]);
            }
        }
        if(mn == cost_max) return false;
        for(int i=0; i<sz; i++) if(!chk[i]) dist[i] += mn;
        return true;
    }
    
    flow_t dfs(int cur, int T, flow_t flow){
        chk[cur] = 1;
        if(cur == T) return flow;
        for(; work[cur]<adj[cur].size(); work[cur]++){
            auto &i = adj[cur][work[cur]];
            if(!chk[i.v] && dist[i.v] == dist[cur] + i.d && i.c){
                flow_t ret = dfs(i.v, T, min(flow, i.c));
                if(ret > 0){
                    i.c -= ret;
                    adj[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    
    pair<cost_t, flow_t> get_MCMF(int S, int T){ //{cost, flow}
        init(S, T);
        cost_t cost = 0;
        flow_t flow = 0, tmp;
        do{
            memset(chk, 0, sizeof(chk));
            memset(work, 0, sizeof(work));
            while((tmp = dfs(S, T, flow_max)) > 0){
                cost += dist[T] * tmp;
                flow += tmp;
                memset(chk, 0, sizeof(chk));
            }
        }while(update());
        return {cost, flow};
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    int S = 0, T = N + M + 1;
    MCMF<int, int, 10010> mcmf;
    for(int i=1; i<=N; i++){
        int c; cin >> c;
        mcmf.addEdge(S, i, c, 0);
    }
    for(int i=1; i<=M; i++){
        int c; cin >> c;
        mcmf.addEdge(i + N, T, c, 0);
    }
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            int d; cin >> d;
            mcmf.addEdge(j, i + N, mcmf.flow_max, d);
        }
    }

    cout << mcmf.get_MCMF(S, T).first << '\n';

    return 0;
}