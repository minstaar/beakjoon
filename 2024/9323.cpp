#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int N, M, S, E, s, p, y;
vector<tuple<int, int, int>> adj[210];
const double INF = 1e9;

double dijkstra()
{
    vector<double> dist(N+1, INF);
    vector<vector<double>> dp(N+1, vector<double>(2, INF));
    priority_queue<pair<double, int>> pq;
    pq.push({0, S}); dist[S] = 0; dp[S][0] = s; dp[S][1] = 0;
    while(!pq.empty()){
        double cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] != cost) continue;
        for(auto [next, nextP, nextCost]: adj[cur]){
            dp[next][0] = min(dp[next][0], min(dp[cur][0] + nextCost * p, dp[cur][1] + nextCost * p + s));
            dp[next][1] = min(dp[next][1], min(dp[cur][0], dp[cur][1]) + (double)(y + nextCost * p) * (double)nextP / 100);
            double tmp = min(dp[next][0], dp[next][1]);
            if(dist[next] > tmp){
                dist[next] = tmp;
                pq.push({-dist[next], next});
            }
        }
    }
    return dist[E];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout << fixed;
    cout.precision(2);
    int T; cin >> T;
    while(T--){
        cin >> N >> M >> S >> E;
        cin >> s >> p >> y;
        for(int i=1; i<=N; i++) adj[i].clear();
        for(int i=0; i<M; i++){
            int u, v, c, w; cin >> u >> v >> c >> w;
            adj[u].push_back({v, c, w});
            adj[v].push_back({u, c, w});
        }
        cout << dijkstra() << '\n';
    }

    return 0;
}