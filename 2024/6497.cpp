#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
    Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {};
    bool operator < (const Edge& other){
        return cost < other.cost;
    }
};

int parent[200010];

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
    parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        int V, E; cin >> V >> E;
        if(V == 0 && E == 0) break;
        vector<Edge> adj;
        int sum = 0, cnt = 0;
        for(int i=0; i<V; i++) parent[i] = i;
        for(int i=0; i<E; i++){
            int a, b, w; cin >> a >> b >> w;
            adj.push_back({a, b, w});
            sum += w;
        }

        sort(adj.begin(), adj.end());

        for(int i=0; i<E; i++){
            int x = Find(adj[i].from);
            int y = Find(adj[i].to);
            if(x != y){
                Union(x, y);
                cnt += adj[i].cost;
            }
        }
        cout << sum - cnt << '\n';
    }

    return 0;
}