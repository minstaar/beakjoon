#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int from;
    int to;
    long long cost;
    bool operator < (const Edge& other){
        return cost < other.cost;
    }
};

int parent[1010];

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

    int N; cin >> N;
    vector<Edge> adj;
    long long ans = 0;
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int c; cin >> c;
            if(i < j) adj.push_back({i, j, c});
        }
    }
    
    sort(adj.begin(), adj.end());
    for(auto cur: adj){
        int x = Find(cur.from);
        int y = Find(cur.to);
        if(x != y){
            Union(x, y);
            ans += cur.cost;
        }
    }

    cout << ans << '\n';

    return 0;
}