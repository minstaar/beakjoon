#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[300010];
int N, A, B, ans;

pair<bool, int> dfs(int prev, int cur)
{
    if(cur == B) return {true, 0};
    int cnt = 1;
    bool flag = false;
    for(auto next: adj[cur]){
        if(prev == next) continue;
        auto [isPath, sub] = dfs(cur, next);
        if(cur == A && isPath) ans = sub;
        flag |= isPath;
        cnt += sub;
    }
    if(flag) return {true, cnt};
    else return {false, cnt};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(-1, A);
    cout << ans << '\n';

    return 0;
}