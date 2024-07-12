#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;
vector<pii> adj[5010], rev[5010];
int N, B, S, R;
vector<ll> dist(5010, INF), rdist(5010, INF);
ll psum[5010], dp[5010][5010];

void dijkstra(int start)
{
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        ll curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] > curDist) continue;
        for(auto [next, nextDist]: adj[cur]){
            if(dist[next] > dist[cur] + nextDist){
                dist[next] = dist[cur] + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }

    pq.push({0, start});
    rdist[start] = 0;
    while(!pq.empty()){
        ll curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(rdist[cur] > curDist) continue;
        for(auto [next, nextDist]: rev[cur]){
            if(rdist[next] > rdist[cur] + nextDist){
                rdist[next] = rdist[cur] + nextDist;
                pq.push({-rdist[next], next});
            }
        }
    }
}

void solve(int t, int s, int e, int optl, int optr)
{
    if(s > e) return;
    int m = s + e >> 1;
    int opt = m;
    dp[t][m] = INF;
    for(int k=optl; k<=min(optr, m-1); k++){
        ll val = dp[t-1][k] + (psum[m] - psum[k]) * (m - k - 1);
        if(dp[t][m] > val){
            dp[t][m] = val;
            opt = k;
        }
    }
    solve(t, s, m - 1, optl, opt);
    solve(t, m + 1, e, opt, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> B >> S >> R;
    for(int i=0; i<R; i++){
        int u, v, l; cin >> u >> v >> l;
        adj[u].push_back({v, l});
        rev[v].push_back({u, l});
    }

    dijkstra(B + 1);
    for(int i=1; i<=B; i++){
        psum[i] = dist[i] + rdist[i];
    }
    sort(psum + 1, psum + B + 1);
    for(int i=2; i<=B; i++){
        psum[i] += psum[i-1];
    }

    for(int i=1; i<=B; i++){
        dp[0][i] = psum[i] * (i - 1);
    }
    for(int i=1; i<S; i++){
        solve(i, 1, B, 1, B);
    }
    cout << dp[S-1][B] << '\n';

    return 0;
}