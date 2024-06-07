#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[210];
int dfn[210], id;
bool flag;

int dfs(int prev, int cur)
{
    dfn[cur] = ++id;
    int cycle = 0, close = 0;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        if(dfn[next] == 0){
            cycle += dfs(cur, next);
        }
        else if(dfn[cur] > dfn[next]) cycle++;
        else if(dfn[cur] < dfn[next]) close++;
    }
    if(cycle >= 2) flag = true;
    return cycle - close;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        if(dfn[i] == 0){
            flag = false;
            dfs(0, i);
            if(!flag) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}