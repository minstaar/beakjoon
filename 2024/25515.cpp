#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> adj[100010];
ll arr[100010];

ll dfs(int prev, int cur)
{
    ll ret = arr[cur];
    for(auto next: adj[cur]){
        if(prev == next) continue;
        ll tmp = dfs(cur, next);
        if(tmp > 0) ret += tmp;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<N; i++) cin >> arr[i];

    cout << dfs(-1, 0) << '\n';

    return 0;
}