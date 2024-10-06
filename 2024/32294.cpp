#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll INF = 1e18;
int N, A[200010], B[200010], E;
vector<pair<int, ll>> adj[200010];
vector<ll> dist(200010, INF);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];

    for(int i=1; i<=N; i++){
        int u1 = i - A[i];
        if(u1 < 0) u1 = 0;
        int u2 = i + A[i];
        if(u2 > N) u2 = 0;
        adj[u1].push_back({i, B[i]});
        if(u1 != u2) adj[u2].push_back({i, B[i]});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        auto [curCost, cur] = pq.top(); pq.pop();
        curCost = -curCost;
        if(curCost > dist[cur]) continue;
        for(auto [next, nextCost]: adj[cur]){
            if(dist[next] > dist[cur] + nextCost){
                dist[next] = dist[cur] + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }

    for(int i=1; i<=N; i++) cout << dist[i] << ' ';
    
    return 0;
}