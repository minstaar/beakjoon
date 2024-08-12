#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind{
    vector<int> parent;
    UnionFind(int n): parent(n, -1) {}
    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }
    bool Union(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x == y) return false;
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

struct Edge{
    int u, v, c;
    int idx;
    bool operator < (const Edge &o) const{
        return c < o.c;
    }
};

vector<Edge> edges;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    UnionFind UF(N + 1);

    for(int i=1; i<=M; i++){
        int u, v, c; cin >> u >> v >> c;
        edges.push_back({u, v, c, i});
    }

    if(N - 1 == M){
        cout << "NO\n";
    }
    else{
        sort(edges.begin(), edges.end());
        Edge e = {0, 0, 0, -1};
        for(int i=0; i<M; i++){
            if(!UF.Union(edges[i].u, edges[i].v) && e.idx == -1){
                e = edges[i];
                break;
            }
        }

        vector<int> res = {e.idx};
        UF.parent = vector<int>(N + 1, -1);
        UF.Union(e.u, e.v);
        for(int i=0; i<M; i++){
            if(UF.Union(edges[i].u, edges[i].v)){
                res.push_back(edges[i].idx);
            }
        }

        cout << "YES\n";
        for(auto x: res) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}