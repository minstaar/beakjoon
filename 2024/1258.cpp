#include <bits/stdc++.h>
using namespace std;

template<typename flow_t, typename cost_t>
struct MCMF{
    struct Edge{int v, dual; flow_t c; cost_t d;};
    vector<vector<Edge>> adj;
    flow_t flow_max = numeric_limits<flow_t>::max() / 2;
    cost_t cost_max = numeric_limits<cost_t>::max() / 2;
    int n;
    vector<int> inQue, chk, work;
    vector<cost_t> h, dist;

    MCMF(int n): n(n), adj(n), inQue(n), h(n), dist(n), chk(n), work(n) {}

    void addEdge(int s, int e, flow_t c, cost_t d){
        adj[s].push_back({e, (int)adj[e].size(), c, d});
        adj[e].push_back({s, (int)adj[s].size() - 1, 0, -d});
    }

    void init(int S, int T){
        fill(h.begin(), h.end(), cost_max);
        fill(dist.begin(), dist.end(), cost_max);
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
        for(int i=0; i<n; i++){
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
        for(int i=0; i<n; i++) dist[i] += h[T] - h[S];
    }

    bool update(){
        cost_t mn = cost_max;
        for(int i=0; i<n; i++) if(chk[i]){
            for(auto j: adj[i]) if(j.c && !chk[j.v]){
                mn = min(mn, dist[i] + j.d - dist[j.v]);
            }
        }
        if(mn == cost_max) return false;
        for(int i=0; i<n; i++) if(!chk[i]) dist[i] += mn;
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
            fill(chk.begin(), chk.end(), 0);
            fill(work.begin(), work.end(), 0);
            while((tmp = dfs(S, T, flow_max)) > 0){
                cost += dist[T] * tmp;
                flow += tmp;
                fill(chk.begin(), chk.end(), 0);
            }
        }while(update());
        return {cost, flow};
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int S = 0, T = N * 2 + 1;
    MCMF<int, int> mcmf(250010);
    for(int i=1; i<=N; i++){
        mcmf.addEdge(S, i, 1, 0);
        mcmf.addEdge(i + N, T, 1, 0);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int w; cin >> w;
            mcmf.addEdge(i, j + N, 1, w);
        }
    }
    cout << mcmf.get_MCMF(S, T).first << '\n';

    return 0;
}