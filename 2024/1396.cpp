#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;
    bool operator<(const Edge& other){
        return cost < other.cost;
    }
    Edge(){}
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

struct UnionFind
{
    int parent[100010];
    void init()
    {
        memset(parent, -1, sizeof(parent));
    }
    int Find(int x)
    {
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }
    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if(x != y){
            if(parent[x] > parent[y]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
};

Edge adj[100010];
UnionFind UF;
int query[100010][2], l[100010], r[100010];
int ans[100010][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> adj[i].from >> adj[i].to >> adj[i].cost;
    }

    sort(adj+1, adj+M+1);
    int Q; cin >> Q;
    for(int i=1; i<=Q; i++){
        cin >> query[i][0] >> query[i][1];
        l[i] = 1;
        r[i] = M + 1;
    }

    while(1){
        bool flag = false;
        vector<int> mid[100010];
        for(int i=1; i<=Q; i++){
            if(l[i] < r[i]){
                flag = true;
                mid[(l[i]+r[i])/2].push_back(i);
            }
        }
        if(!flag) break;

        UF.init();
        for(int i=1; i<=M; i++){
            int u = adj[i].from;
            int v = adj[i].to;
            int c = adj[i].cost;
            if(UF.Find(u) != UF.Find(v)) UF.Union(u, v);

            for(int j: mid[i]){
                int a = UF.Find(query[j][0]);
                int b = UF.Find(query[j][1]);
                if(a == b){
                    r[j] = i;
                    ans[j][0] = c;
                    ans[j][1] = -UF.parent[UF.Find(a)];
                }
                else{
                    l[j] = i + 1;
                }
            }
        }
    }
    
    for(int i=1; i<=Q; i++){
        if(l[i] == M + 1) cout << -1 << '\n';
        else cout << ans[i][0] << " " << ans[i][1] << '\n';
    }

    return 0;
}