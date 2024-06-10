#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10010];
int dfn[10010], low[10010], id;
int vertex_color[10010], color_cnt, res;
bool visited[10010];

int dfs(int cur)
{
    int& ret = low[cur] = dfn[cur] = ++id;
    for(auto next: adj[cur]){
        if(!dfn[next]){
            ret = min(ret, dfs(next));
        }
        else ret = min(ret, dfn[next]);
    }
    return ret;
}

void color(int cur, int p)
{
    if(p) vertex_color[cur]++;
    visited[cur] = true;
    for(auto next: adj[cur]){
        if(visited[next]) continue;
        if(low[next] >= dfn[cur]){
            color_cnt++;
            vertex_color[cur]++;
            res = max(res, vertex_color[cur]);
            color(next, color_cnt);
        }
        else color(next, p);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        int V, E; cin >> V >> E;
        if(V == 0 && E == 0) break;
        memset(dfn, 0, sizeof(dfn[0]) * V);
        memset(low, 0, sizeof(low[0]) * V);
        memset(visited, false, sizeof(visited[0]) * V);
        memset(vertex_color, 0, sizeof(vertex_color[0]) * V);
        for(int i=0; i<V; i++) adj[i].clear();
        id = color_cnt = 0;

        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<V; i++){
            if(!dfn[i]) dfs(i);
        }
        vector<int> art_cnt;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                res = 0;
                color(i, 0);
                art_cnt.push_back(res);
            }
        }

        int ans = 0, sz = art_cnt.size();
        for(int i=0; i<sz; i++){
            ans = max(ans, art_cnt[i] + sz - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}