#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[1010];
int l[1010], r[1010];
bool visited[1010];

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visited[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        for(int i=0; i<1010; i++) adj[i].clear();
        int V, E; cin >> V >> E;
        for(int i=0; i<E; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        int match = 0;
        memset(l, -1, sizeof(l));
        memset(r, -1, sizeof(r));
        for(int i=0; i<V; i++){
            if(l[i] == -1){
                memset(visited, false, sizeof(visited));
                if(dfs(i)) match++;
            }
        }
        cout << match << '\n';
    }

    return 0;
}