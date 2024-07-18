#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int N, M, K;
int dp[310][310];
vector<pii> adj[310];

int solve(int cur, int used)
{
    if(cur == N) return 0;
    if(used >= M) return -1e9;
    int &ret = dp[cur][used];
    if(ret != -1) return ret;
    ret = -1e9;
    for(auto [next, nextDist]: adj[cur]){
        ret = max(ret, solve(next, used + 1) + nextDist);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<K; i++){
        int u, v, w; cin >> u >> v >> w;
        if(u < v) adj[u].push_back({v, w});
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 1) << '\n';
    return 0;
}