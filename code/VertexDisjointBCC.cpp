#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct BCC{
    vector<vector<pii>> adj;
    vector<int> dfn, low, check;
    vector<bool> visited;
    vector<vector<int>> bcc;
    int n, id, art_point, color_cnt;

    BCC(int n): n(n), adj(n+1) {}

    void addEdge(int u, int v, int idx){
        adj[u].push_back({v, idx});
        adj[v].push_back({u, idx});
    }

    int dfs(int cur, bool isRoot){
        int& ret = low[cur] = dfn[cur] = ++id;
        int child = 0;
        for(auto [next, idx]: adj[cur]){
            if(!dfn[next]){
                int t = dfs(next, false);
                if(t >= dfn[cur] && !isRoot && !check[cur]){
                    check[cur] = ++art_point;
                }
                ret = min(ret, t);
                child++;
            }
            else ret = min(ret, dfn[next]);
        }
        if(isRoot && child >= 2) check[cur] = ++art_point;
        return ret;
    }

    void color(int cur, int p){
        if(p) bcc[cur].push_back(p);
        visited[cur] = true;
        for(auto [next, idx]: adj[cur]){
            if(visited[next]) continue;
            if(low[next] >= dfn[cur]) {
                bcc[cur].push_back(++color_cnt);
                color(next, color_cnt);
            }
            else color(next, p);
        }
    }

    void get_bcc(){
        dfn = vector<int>(n+1);
        low = vector<int>(n+1);
        check = vector<int>(n+1);
        visited = vector<bool>(n+1);
        id = art_point = color_cnt = 0;
        for(int i=1; i<=n; i++){
            if(!dfn[i]) dfs(i, true);
        }
        bcc = vector<vector<int>>(n+1);
        for(int i=1; i<=n; i++){
            if(!visited[i]) color(i, 0);
        }
    }
};