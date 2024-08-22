#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;
int N, M;
vector<pii> adj[100010];
vector<ll> dist(100010, INF), cnt(100010), dp(100010, -1);

void dijkstra(int s)
{
    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        ll curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < curDist) continue;
        for(auto [next, cost]: adj[cur]){
            if(dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

void bfs(int s)
{
    queue<int> que;
    que.push(s);
    cnt[s] = 1;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto [next, cost]: adj[cur]){
            if(!cnt[next] && dist[next] == dist[cur] + cost){
                cnt[next] = cnt[cur] + 1;
                que.push(next);
            }
        }
    }
}

const ll MOD = 1e9 + 9;
ll solve(int cur, int dest)
{
    if(cur == dest) return 1;
    ll &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    for(auto [next, cost]: adj[cur]){
        if(cnt[next] == cnt[cur] + 1 && dist[next] == dist[cur] + cost) ret = (ret + solve(next, dest)) % MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int s, e;
    cin >> N >> M >> s >> e;
    for(int i=0; i<M; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    dijkstra(s);
    bfs(s);
    solve(s, e);

    if(dist[e] == INF) cout << "-1\n";
    else cout << dist[e] << '\n' << cnt[e] - 1 << '\n' << dp[s] << '\n';

    return 0;
}