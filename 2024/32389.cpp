#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int dp[100010][15];
bool check[100010];
vector<int> adj[100010];

int dfs(int prev, int cur) //returns the number of repairable lights
{
    int sum = 0;
    int tmp[15] = {};
    for(auto next: adj[cur]){
        if(prev == next) continue;

        int cnt = dfs(cur, next);
        for(int i=0; i<=10; i++) tmp[i] = dp[cur][i];
        for(int i=0; i<=min(K, sum+cnt); i++){
            for(int j=0; j<=i; j++){
                if(i - j <= sum && j <= cnt){
                    dp[cur][i] = max(dp[cur][i], tmp[i-j] + dp[next][j]);
                }
            }
        }
        sum += cnt;
    }
    if(check[cur]){
        sum++;
        for(int i=min(sum, K); i>0; i--){
            dp[cur][i] = dp[cur][i-1] + 1;
        }
        dp[cur][0] = 0;
    }
    else{
        for(int i=0; i<=min(sum, K); i++){
            dp[cur][i] += 1;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<M; i++){
        int a; cin >> a;
        check[a] = true;
    }

    if(M <= K){
        cout << N << '\n';
    }
    else{
        dfs(0, 1);
        cout << dp[1][K] << '\n';
    }

    return 0;
}