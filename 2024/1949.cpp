#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[10010], dp[10010][2];
vector<int> tree[10010];
bool visited[10010];

void dfs(int cur)
{
    dp[cur][1] = arr[cur];
    for(auto next: tree[cur]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}