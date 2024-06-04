#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> ans;
vector<int> adj[100010];
int dfn[100010], id;

int dfs(int prev, int cur)
{
    int ret = dfn[cur] = ++id;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        if(dfn[next] > 0){
            ret = min(ret, dfn[next]);
        }
        else{
            int low = dfs(cur, next);
            if(low > dfn[cur]){
                ans.push_back({min(cur, next), max(cur, next)});
            }
            ret = min(ret, low);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V, E; cin >> V >> E;
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=V; i++){
        if(dfn[i] == 0) dfs(0, i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto x: ans){
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}