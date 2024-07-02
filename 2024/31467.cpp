#include <bits/stdc++.h>
using namespace std;

struct BCC{
    vector<vector<int>> adj;
    vector<int> dfn, low, check;
    vector<bool> visited;
    vector<vector<int>> bcc;
    int n, id, art_point, color_cnt;

    BCC(int n): n(n), adj(n+1) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int cur, bool isRoot){
        int& ret = low[cur] = dfn[cur] = ++id;
        int child = 0;
        for(auto next: adj[cur]){
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
        for(auto next: adj[cur]){
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
        for(int i=0; i<n; i++){
            if(!dfn[i]) dfs(i, true);
        }
        bcc = vector<vector<int>>(n+1);
        for(int i=0; i<n; i++){
            if(!visited[i]) color(i, 0);
        }
    }
};

BCC bcc(1000010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int edge = 0, vertex = 0;
    vector<string> str(N);
    for(int i=0; i<N; i++) cin >> str[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(str[i][j] == '.') continue;
            if(j + 1 < N && str[i][j+1] == '#'){
                bcc.addEdge(i*N+j, i*N+j+1);
                edge++;
            }
            if(i + 1 < N && str[i+1][j] == '#'){
                bcc.addEdge(i*N+j, (i+1)*N+j);
                edge++;
            }
            vertex++;
        }
    }

    bcc.get_bcc();
    vector<pair<int, int>> res;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(str[i][j] == '.') continue;
            if(bcc.bcc[i*N+j].size() > 1) continue;
            if(vertex == edge - bcc.adj[i*N+j].size() + 2){
                res.push_back({i + 1, j + 1});
            }
        }
    }
    cout << res.size() << '\n';
    for(auto x: res) cout << x.first << ' ' << x.second << '\n';

    return 0;
}