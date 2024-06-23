#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[510];
int l[510], r[510];
bool visited[510];

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

    int N, K; cin >> N >> K;
    for(int i=0; i<K; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    int res = 0;
    for(int i=0; i<N; i++){
        if(l[i] == -1){
            memset(visited, false, sizeof(visited));
            if(dfs(i)) res++;
        }
    }
    cout << res << '\n';

    return 0;
}