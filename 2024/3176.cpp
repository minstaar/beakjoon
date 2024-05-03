#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 15
using namespace std;

typedef pair<int, int> pii;
vector<pii> adj[100010];
int parent[100010][MAX], depth[100010], dist[100010];

void makeTree(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next.first] == -1){
            parent[next.first][0] = cur;
            depth[next.first] = depth[cur] + 1;
            dist[next.first]
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    makeTree(1);
}