#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<int> adj[200010];
ll W[200010], dp[200010], beauti, ans;

void makeTree(int prev, int cur, int depth)
{
    dp[cur] = W[cur];
    beauti += W[cur] * depth;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        makeTree(cur, next, depth + 1);
        dp[cur] += dp[next];
    }
}

void solve(int prev, int cur, ll cost)
{
    ans = max(ans, cost);
    for(auto next: adj[cur]){
        if(next == prev) continue;
        solve(cur, next, cost + dp[1] - 2 * dp[next]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=N; i++) cin >> W[i];
    makeTree(0, 1, 0);
    solve(0, 1, beauti);

    cout << ans << '\n';

    return 0;
}