#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100010], dp(100010);
int ans;

void dfs(int prev, int cur)
{
    for(auto next: adj[cur]) if(next != prev){
        dfs(cur, next);
        if(!dp[cur] && !dp[next]){
            dp[cur] = 1;
            ans++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 1);
    cout << ans << '\n';

    return 0;
}