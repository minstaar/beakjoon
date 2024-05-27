#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
struct Edge
{
    ll to;
    ll cost;
    ll time;
};

ll N, M;
vector<Edge> adj[100010];

ll dijkstra(ll src, ll delay)
{
    priority_queue<pll, vector<pll>, greater<>> pq;
    vector<ll> dist(N+1, INF);
    pq.push({delay, src});
    dist[src] = delay;
    while(!pq.empty()){
        auto [curCost, cur] = pq.top();
        pq.pop();
        if(curCost > dist[cur]) continue;
        for(auto next: adj[cur]){
            if(dist[cur] + next.cost < dist[next.to] && dist[cur] + next.cost <= next.time){
                dist[next.to] = dist[cur] + next.cost;
                pq.push({dist[next.to], next.to});
            }
        }
    }
    return dist[N];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        ll u, v, d, t; cin >> u >> v >> d >> t;
        adj[u].push_back({v, d, t});
        adj[v].push_back({u, d, t});
    }

    ll lo = 0, hi = 1e9;
    while(lo <= hi){
        ll mid = lo + hi >> 1LL;
        if(dijkstra(1, mid) != INF){
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << hi << '\n';

    return 0;
}