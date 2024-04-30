#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100010];
bool visited[100010];
int dp[100010];

int dfs(int cur)
{
    dp[cur] = 1;
    for(auto x: tree[cur]){
        if(!visited[x]){
            visited[x] = true;
            dp[cur] += dfs(x);
        }
    }
    return dp[cur];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, R, Q; cin >> N >> R >> Q;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[R] = true;
    dfs(R);

    for(int i=0; i<Q; i++){
        int node; cin >> node;
        cout << dp[node] << '\n';
    }

    return 0;
}