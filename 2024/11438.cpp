#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int parent[100010][18], depth[100010];
vector<int> adj[100010];

void makeTree(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next] == -1){
            parent[next][0] = cur;
            depth[next] = depth[cur] + 1;
            makeTree(next);
        }
    }
}

int query(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++){
        if(diff % 2) u = parent[u][i];
        diff /= 2;
    }
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    makeTree(1);
    for(int k=0; k<=17; k++){
        for(int i=2; i<=N; i++){
            if(parent[i][k] != -1){
                parent[i][k+1] = parent[parent[i][k]][k];
            }
        }
    }

    int M; cin >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        cout << query(u, v) << '\n';
    }

    return 0;
}