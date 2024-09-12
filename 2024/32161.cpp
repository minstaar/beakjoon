#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n): parent(n, -1){};

    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y) return;
        parent[x] += parent[y];
        parent[y] = x;
    }
};

vector<int> adj[4010];
map<int, int> mp; int pv;
int dist[4010][4010];
const int INF = 1e9;

void floyd()
{
    for(int k=0; k<pv; k++){
        for(int i=0; i<pv; i++){
            if(dist[i][k] == INF) continue;
            for(int j=0; j<pv; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, Q; cin >> N >> M >> Q;

    UnionFind UF(2 * M);

    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        if(mp.find(u) == mp.end()) mp[u] = pv++;
        if(mp.find(v) == mp.end()) mp[v] = pv++;
        UF.Union(mp[u], mp[v]);
        adj[mp[u]].push_back(mp[v]);
        adj[mp[v]].push_back(mp[u]);
        dist[mp[u]][mp[v]] = dist[mp[v]][mp[u]] = 1;
    }

    int x = UF.Find(0);
    if(-UF.parent[x] == N){
        for(int i=0; i<pv; i++){
            for(int j=0; j<pv; j++){
                if(i != j && !dist[i][j]) dist[i][j] = INF;
            }
        }
        floyd();
        while(Q--){
            int s, e; cin >> s >> e;
            cout << dist[mp[s]][mp[e]] << '\n';
        }
    }
    else{
        while(Q--){
            int s, e; cin >> s >> e;
            if(s == e) cout << "0\n";
            else if(mp.find(s) == mp.end() || mp.find(e) == mp.end() || UF.Find(mp[s]) != UF.Find(mp[e])) cout << "1\n";
            else{
                bool flag = false;
                for(auto next: adj[mp[s]]){
                    if(next == mp[e]){
                        flag = true;
                        break;
                    }
                }
                cout << (flag ? 1 : 2) << '\n';
            }
        }
    }

    return 0;
}