#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int N, K, sz[200010];
bool visited[200010];
vector<pii> adj[200010];
map<int, int> m;

int getSize(int prev, int cur)
{
    sz[cur] = 1;
    for(auto [next, cost]: adj[cur]){
        if(!visited[next] && next != prev){
            sz[cur] += getSize(cur, next);
        }
    }
    return sz[cur];
}

int getCent(int prev, int cur, int cnt)
{
    for(auto [next, cost]: adj[cur]){
        if(!visited[next] && next != prev && sz[next] * 2 > cnt){
            return getCent(cur, next, cnt);
        }
    }
    return cur;
}

void update(int prev, int cur, int dist, int depth)
{
    if(dist > K) return;
    
    auto it = m.find(dist);
    if(it != m.end()) it->second = min(it->second, depth);
    else m[dist] = depth;

    for(auto [next, cost]: adj[cur]){
        if(next != prev && !visited[next]){
            update(cur, next, dist + cost, depth + 1);
        }
    }
}

int solve(int prev, int cur, int dist, int depth)
{
    int ret = INF;
    if(dist > K) return ret;
    
    auto it = m.find(K - dist);
    if(it != m.end()) ret = min(ret, it->second + depth);
    
    for(auto [next, cost]: adj[cur]){
        if(next != prev && !visited[next]){
            ret = min(ret, solve(cur, next, dist + cost, depth + 1));
        }
    }
    return ret;
}

int dnc(int prev, int cur)
{
    int cnt = getSize(-1, cur);
    int cent = getCent(-1, cur, cnt);
    visited[cent] = true;
    
    int ret = INF;
    m.clear();
    m[0] = 0;

    for(auto [next, cost]: adj[cent]){
        if(!visited[next]){
            ret = min(ret, solve(cent, next, cost, 1));
            update(cent, next, cost, 1);
        }
    }
    for(auto [next, cost]: adj[cent]){
        if(!visited[next]){
            ret = min(ret, dnc(cur, next));
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N-1; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    int ans = dnc(-1, 0);
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}