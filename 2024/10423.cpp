#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
    bool operator < (const Edge& other){
        return cost < other.cost;
    }
};

int parent[1010];
bool gen[1010];

int Find(int x)
{
    if(parent[x] == x) return x;
    else{
        return parent[x] = Find(parent[x]);
    }
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(gen[x] == true) parent[y] = x;
    else parent[x] = y;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<Edge> adj;
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=0; i<K; i++){
        int a; cin >> a;
        gen[a] = true;
    }
    for(int i=0; i<M; i++){
        int v1, v2, c; cin >> v1 >> v2 >> c;
        adj.push_back({v1, v2, c});
    }

    sort(adj.begin(), adj.end());
    long long ans = 0;
    for(auto cur: adj){
        int x = Find(cur.from);
        int y = Find(cur.to);
        if(gen[x] == 1 && gen[y] == 1) continue;
        if(x != y){
            Union(x, y);
            ans += cur.cost;
        }
    }
    cout << ans << '\n';

    return 0;
}