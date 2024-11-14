#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N, P;
vector<int> adj[100010];
vector<pii> arr(100010);

int dfs(int prev, int cur)
{
    int ret = 0;
    for(auto next: adj[cur]){
        if(prev == next) continue;
        ret += dfs(cur, next);
    }
    int diff = arr[cur].second - arr[cur].first;
    return max(0, ret + diff);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> P;
    for(int i=1; i<=N; i++) cin >> arr[i].first;
    for(int i=1; i<=N; i++) cin >> arr[i].second;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(0, P) << '\n';

    return 0;
}