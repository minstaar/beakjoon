#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int N;
int sub[100010];
bool check[100010];
vector<int> adj[100010];
ll res;

pair<bool, int> dfs(int prev, int cur)
{
    if(cur == N) check[cur] = true;
    for(auto next: adj[cur]){
        if(prev == next) continue;
        auto [flag, cnt] = dfs(cur, next);
        check[cur] |= flag;
        sub[cur] += cnt;
    }
    sub[cur] += check[cur] ? 0 : 1;
    return {check[cur], sub[cur]};
}

void dfs2(int prev, int cur)
{
    int node = -1;
    ll cnt = 0;
    for(auto next: adj[cur]){
        if(prev == next) continue;
        if(check[next]) node = next;
        res += cnt * sub[next];
        cnt += sub[next];
    }
    if(node != -1) dfs2(cur, node);
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
    dfs2(0, 1);

    cout << res << '\n';

    return 0;
}