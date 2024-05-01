#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[1000010];
int dp[1000010][2];
bool visited[1000010];

void dfs(int cur)
{
    dp[cur][1] = 1;
    for(auto next: tree[cur]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}