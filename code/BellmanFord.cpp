#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> adj[100010];

vector<ll> bellmanFord(int n, int src){
    vector<ll> dist(n+1, 1e18);
    dist[src] = 0;
    bool updated;

    for(int i=1; i<=n; i++){
        updated = false;
        for(int cur=1; cur<=n; cur++){
            for(auto [next, cost]: adj[cur]){
                if(dist[next] > dist[cur] + cost){
                    dist[next] = dist[cur] + cost;
                    updated = true;
                    if(i == n) return vector<ll>();
                }
            }
        }
        if(!updated) break;
    }
    return dist;
}

void addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
}