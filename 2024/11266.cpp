#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10010], ans;
int dfn[10010], id;

int dfs(int prev, int cur, bool isRoot)
{
    int ret = dfn[cur] = ++id;
    int child = 0;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        if(dfn[next] > 0){
            ret = min(ret, dfn[next]);
        }
        else{
            child++;
            int low = dfs(cur, next, false);
            if(!isRoot && low >= dfn[cur]){
                ans.push_back(cur);
            }
            ret = min(ret, low);
        }
    }
    if(isRoot && child >= 2){
        ans.push_back(cur);
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
        if(dfn[i] == 0) dfs(0, i, true);
    }
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << ' ';
    cout << '\n';

    return 0;
}