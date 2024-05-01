#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int W[10010], dp[10010][2];
bool visited[10010], subset[10010];
vector<int> tree[10010], ans;

void dfs(int cur)
{
    dp[cur][1] = W[cur];
    for(auto next: tree[cur]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            if(dp[next][0] <= dp[next][1]) subset[next] = true;
            dp[cur][1] += dp[next][0];
        }
    }
}

void path(int cur, bool flag)
{
    visited[cur] = true;
    if(flag){
        ans.push_back(cur);
        for(auto next: tree[cur]){
            if(visited[next]) continue;
            path(next, 0);
        }
    }
    else{
        for(auto next: tree[cur]){
            if(visited[next]) continue;
            path(next, subset[next]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> W[i];
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << '\n';
    memset(visited, false, sizeof(visited));
    path(1, dp[1][0] <= dp[1][1] ? true : false);
    sort(ans.begin(), ans.end());
    for(auto x: ans) cout << x << " ";

    return 0;
}