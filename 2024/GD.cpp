#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll pre[2010], res;
vector<int> adj[2010];
int dp[2010][2010];
int N;

void dfs(int id, int prev, int cur, int depth)
{
    for(auto next: adj[cur]){
        if(next == prev) continue;
        dfs(id, cur, next, depth + 1);
        dp[id][depth]++;
    }
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

    pre[0] = 1;
    for(int i=1; i<=2000; i++) pre[i] = pre[i-1] * 2 % MOD;

    for(int i=1; i<=N; i++){
        int pv = 0;
        if(adj[i].size() <= 1) continue;
        res = (res + 1) % MOD;
        memset(dp, 0LL, sizeof(dp));
        for(auto next: adj[i]){
            dfs(pv, i, next, 0);
            pv++;
        }

        int depth = 0;
        while(1){
            ll tmp = 1;
            for(int j=0; j<pv; j++){
                tmp = tmp * (pre[dp[j][depth]] - 1) % MOD;
            }
            if(tmp == 0) break;
            res = (res + tmp) % MOD;
            depth++;
        }
    }
    cout << res << '\n';

    return 0;
}

