#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int N;
vector<int> adj[100010], grundy(100010);

void dfs(int prev, int cur)
{
    bitset<110> mex;
    for(auto next: adj[cur]){
        if(prev == next) continue;
        dfs(cur, next);
        mex[grundy[next]] = 1;
    }
    int g = 0;
    while(mex[g]) g++;
    grundy[cur] = g;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 1);
    for(int i=1; i<=N; i++){
        cout << (grundy[i] ? "donggggas\n" : "uppercut\n");
    }

    return 0;
}