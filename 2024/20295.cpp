#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 18;
int parent[100010][MAX], depth[100010];
int mask[100010][MAX], node[100010];
vector<int> adj[100010];

void dfs(int cur)
{
    for(auto next: adj[cur]){
        if(depth[next] == -1){
            depth[next] = depth[cur] + 1;
            parent[next][0] = cur;
            mask[next][0] = 1 << node[cur];
            dfs(next);
        }
    }
}

bool get_lca(int u, int v, int k)
{
    int state = 0;
    state |= (1 << node[u]);
    state |= (1 << node[v]);
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++){
        if(diff % 2){
            state |= mask[u][i];
            u = parent[u][i];
        }
        diff /= 2;
    }
    if(u != v){
        for(int i=MAX-1; i>=0; i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                state |= mask[u][i];
                state |= mask[v][i];
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        state |= mask[u][0];
        u = parent[u][0];
    }
    return state & (1 << k);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    bool check[6] = {};
    for(int i=1; i<=N; i++){
        cin >> node[i];
        check[node[i]] = true;
    }
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    dfs(1);
    for(int i=0; i<=MAX-2; i++){
        for(int j=2; j<=N; j++){
            if(parent[j][i] != -1){
                parent[j][i+1] = parent[parent[j][i]][i];
                mask[j][i+1] = mask[parent[j][i]][i] | mask[j][i];
            }
        }
    }

    int Q; cin >> Q;
    int u;
    for(int i=0; i<Q; i++){
        int v, k; cin >> v >> k;
        if(i == 0){
            if(check[k]) cout << "PLAY" << '\n';
            else cout << "CRY" << '\n';
            u = v;
            continue;
        }
        if(get_lca(u, v, k)) cout << "PLAY" << '\n';
        else cout << "CRY" << '\n';
        u = v;
    }

    return 0;
}