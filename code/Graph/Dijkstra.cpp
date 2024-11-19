#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> adj[100010];

vector<ll> dijkstra(int n, int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dist(n+1, 1e18);
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [curCost, cur] = pq.top(); pq.pop();
        if(curCost > dist[cur]) continue;
        for(auto [next, nextCost]: adj[cur]){
            if(dist[next] > dist[cur] + nextCost){
                dist[next] = dist[cur] + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

void addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
}