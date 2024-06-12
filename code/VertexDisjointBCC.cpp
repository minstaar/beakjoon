#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct BCC{
    vector<int> dfn, low, check;
    vector<bool> visited;
    vector<vector<pii>> adj;
    vector<tuple<int, int, int>> edge;
    vector<vector<int>> bcc;
    int n, id, art_point, color_cnt;

    void init(int _n){
        n = _n;
        id = art_point = color_cnt = 0;
        adj.resize(n+1);
        dfn.resize(n+1);
        low.resize(n+1);
        check.resize(n+1);
        visited.resize(n+1);
    }

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
        if(isRoot) check[cur] = (child >= 2 ? ++art_point : 0);
        return ret;
    }

    void color(int cur, int p){
        if(p) bcc[cur].push_back(p);
        visited[cur] = true;
        for(auto [next, idx]: adj[cur]){
            if(low[next] >= dfn[cur]) {
                bcc[cur].push_back(++color_cnt);
                color(next, color_cnt);
            }
            else color(next, p);
        }
    }

    void get_bcc(){
        for(int i=1; i<=n; i++){
            if(!dfn[i]) dfs(-1, i);
        }
        bcc.resize(n+1);
        for(int i=1; i<=n; i++){
            if(!visited[i]) color(i, 0);
        }
    }
}bcc;