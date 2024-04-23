#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
typedef pair<ll, ll> pll;

int N, M, K;
vector<pll> adj[1010];

void dijkstra(int src)
{
    priority_queue<ll, vector<ll>> dist[1010];
    priority_queue<pll, vector<pll>, greater<>> pq;
    dist[src].push(0);
    pq.push({0, src});

    while(!pq.empty()){
        ll cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(auto x: adj[cur]){
            int next = x.first;
            ll nextDist = cost + x.second;
            if(dist[next].size() < K){
                dist[next].push(nextDist);
                pq.push({nextDist, next});
            }
            else if(dist[next].top() > nextDist){
                dist[next].pop();
                dist[next].push(nextDist);
                pq.push({nextDist, next});
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(dist[i].size() < K) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dijkstra(1);

    return 0;
}
