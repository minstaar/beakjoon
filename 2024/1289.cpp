#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<pair<int, int>> adj[100010];
vector<ll> dp[100010];
ll ans;

ll makeTree(int parent, int cur)
{
    int idx = 0;
    ll sum = 0;
    for(auto next: adj[cur]){
        if(next.first == parent) continue;
        dp[cur].push_back(next.second);
        dp[cur][idx] = dp[cur][idx] * (makeTree(cur, next.first) + 1) % MOD;
        if(sum == 0) ans = (ans + dp[cur][idx]) % MOD;
        else {
            ans = (ans + sum * dp[cur][idx]) % MOD;
            ans = (ans + dp[cur][idx]) % MOD;
        }
        sum = (sum + dp[cur][idx]) % MOD;
        idx++;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    makeTree(0, 1);

    cout << ans << '\n';

    return 0;
}