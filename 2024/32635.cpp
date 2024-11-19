#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

vector<pii> adj[1000010], rev[1000010];
int N, M, arr[1000010];
int S, T;

vector<ll> dijkstra(int s, bool flag)
{
    vector<ll> dist(N+1, 1e18);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        auto [curDist, cur] = pq.top();
        curDist *= -1LL;
        pq.pop();
        if(curDist > dist[cur]) continue;
        if(flag){
            for(auto [next, nextDist]: rev[cur]){
                if(dist[next] > dist[cur] + nextDist){
                    dist[next] = dist[cur] + nextDist;
                    pq.push({-dist[next], next});
                }
            }
        }
        else{
            for(auto [next, nextDist]: adj[cur]){
                if(dist[next] > dist[cur] + nextDist){
                    dist[next] = dist[cur] + nextDist;
                    pq.push({-dist[next], next});
                }
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> S >> T;
    for(int i=0; i<M; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        rev[v].push_back({u, c});
    }

    auto dist1 = dijkstra(S, 0);
    auto dist2 = dijkstra(T, 1);

    vector<int> order(N);
    for(int i=0; i<N; i++) order[i] = i + 1;
    sort(order.begin(), order.end(), [&](int &A, int &B){
        return dist1[A] < dist1[B];
    });

    int res = 1e9, mn = 1e9;
    for(auto u: order){
        if(dist1[u] + dist2[u] > dist1[T]) continue;
        for(auto [v, c]: adj[u]){
            if(dist1[u] + dist2[v] + c == dist1[T]){
                mn = min(mn, arr[u]);
                res = min(res, mn + arr[v]);
            }
        }
    }

    if(res == 1e9) cout << "-1\n";
    else cout << res << '\n';

    return 0;
}