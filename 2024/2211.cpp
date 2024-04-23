#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int V, E;
vector<pii> adj[1010];

vector<int> dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(V+1, INF);
    vector<int> parent(V+1);
    for(int i=1; i<=V; i++) parent[i] = i;
    pq.push({0, src});

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;
        for(auto x: adj[cur]){
            int next = x.first;
            int nextDist = cost + x.second;
            if(dist[next] > nextDist){
                dist[next] = nextDist;
                pq.push({nextDist, next});
                parent[next] = cur;
            }
        }
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> ans = dijkstra(1);
    cout << V-1 << '\n';
    for(int i=2; i<=V; i++){
        cout << i << " " << ans[i] << '\n';
    }

    return 0;
}