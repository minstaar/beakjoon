#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> pii;
struct Edge
{
    int from;
    int to;
    int cost;
    bool operator < (const Edge& other){
        return cost < other.cost;
    }
};

pii parent[1010];

pii Find(pii x)
{
    if(parent[x.first].first == x.first) return parent[x.first];
    else{
        if(x.second == 1) parent[x.first].second = 1;
        return parent[x.first] = Find(parent[x.first]);
    }
}

void Union(pii x, pii y)
{
    x = Find(x);
    y = Find(y);
    if(x.first == y.first) return;
    if(x.first == 1) parent[y.first] = Find({x.first, 1});
    else parent[x.first] = Find({y.first, (x.second + y.second)});
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<Edge> adj;
    for(int i=1; i<=N; i++) parent[i].first = i;
    for(int i=0; i<K; i++){
        int a; cin >> a;
        parent[a].second = 1;
    }
    for(int i=0; i<M; i++){
        int v1, v2, c; cin >> v1 >> v2 >> c;
        adj.push_back({v1, v2, c});
    }

    sort(adj.begin(), adj.end());
    long long ans = 0;
    for(auto cur: adj){
        pii x = Find({cur.from, parent[cur.from].second});
        pii y = Find({cur.to, parent[cur.to].second});
        if(x.second == 1 && y.second == 1) continue;
        if(x.first != y.first){
            Union(x, y);
            ans += cur.cost;
        }
    }
    cout << ans << '\n';

    return 0;
}