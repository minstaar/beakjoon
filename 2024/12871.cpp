#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int N;
vector<int> adj[1000010];
int sub[1000010];
ll dp[1000010];

void dfs(int prev, int cur)
{
    sub[cur] = 1;
    dp[cur] = 2 * (N - 1);
    for(auto next: adj[cur]){
        if(prev != next){
            dfs(cur, next);
            sub[cur] += sub[next];
            dp[cur] += 1LL * (N - 1 - sub[next]) * sub[next];
        }
    }
    dp[cur] += 1LL * (N - sub[cur]) * (sub[cur] - 1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 1);
    for(int i=1; i<=N; i++) cout << dp[i] << '\n';

    return 0;
}