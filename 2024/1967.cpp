#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

vector<pii> adj[10010];
int ans;

int dfs(int prev, int cur)
{
    int ret = 0;
    for(auto next: adj[cur]){
        if(next.first == prev) continue;
        int t = dfs(cur, next.first) + next.second;
        ans = max(ans, ret + t);
        ret = max(ret, t);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(0, 1);
    cout << ans << '\n';

    return 0;
}