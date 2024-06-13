#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> adj[100010];

vector<ll> bellmanFord(int n, int src){
    vector<ll> dist(n+1, 1e18);
    vector<bool> inQue(n+1);
    vector<int> cnt(n+1);
    queue<int> que;
    que.push(src);
    inQue[src] = true;
    dist[src] = 0;
    while(!que.empty()){
        int cur = que.front(); que.pop();
        inQue[cur] = false;
        for(auto [next, cost]: adj[cur]){
            if(dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
                if(!inQue[next]){
                    if(++cnt[next] == n) return vector<ll>();
                    que.push(next);
                    inQue[next] = true;
                }
            }
        }
    }
    return dist;
}

void addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
}