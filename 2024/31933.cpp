#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u;
    int v;
    int min;
    int max;
};

struct UnionFind
{
    int parent[5010];
    void init(int N)
    {
        for(int i=1; i<=N; i++) parent[i] = i;
    }
    int Find(int x)
    {
        return x == parent[x] ? x : parent[x] = Find(parent[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x == y) return;
        parent[y] = x;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<Edge> adj(M);
    vector<int> Q;
    for(int i=0; i<M; i++){
        int u, v, l, r; cin >> u >> v >> l >> r;
        adj[i] = {u, v, l, r};
        Q.push_back(l);
        Q.push_back(r + 1);
    }
    Q.push_back(1);
    Q.push_back((int)1e9 + 1);
    int K; cin >> K;
    vector<int> size(K);
    for(int i=0; i<K; i++) cin >> size[i];

    int ans = 0;
    sort(size.begin(), size.end());
    sort(Q.begin(), Q.end());
    for(int i=0; i<Q.size()-1; i++){
        if(Q[i] == Q[i+1]) continue;
        UnionFind uf;
        uf.init(N);
        for(auto edge: adj){
            if(Q[i] >= edge.min && Q[i+1] - 1 <= edge.max){
                uf.Union(edge.u, edge.v);
            }
        }
        if(uf.Find(1) == uf.Find(N)){
            ans += lower_bound(size.begin(), size.end(), Q[i+1]) - lower_bound(size.begin(), size.end(), Q[i]);
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}