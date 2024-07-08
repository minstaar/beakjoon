#include <iostream>
#include <algorithm>
using namespace std;

int arr[4010][4010], psum[4010][4010], cost[4010][4010], dp[810][4010];


void solve(int t, int s, int e, int optl, int optr)
{
    if(s > e) return;
    int m = s + e >> 1;
    int opt = m;
    dp[t][m] = 1e9;
    for(int k=optl; k<=optr; k++){
        int val = dp[t-1][k] + cost[k+1][m];
        if(dp[t][m] > val){
            dp[t][m] = val;
            opt = k;
        }
    }
    solve(t, s, m - 1, optl, opt);
    solve(t, m + 1, e, opt, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            psum[i][j] += psum[i][j-1] + arr[i][j];
        }
    }
    for(int i=1; i<N; i++){
        for(int j=i+1; j<=N; j++){
            cost[i][j] = cost[i][j-1] + psum[j][j] - psum[j][i-1];
        }
    }
    for(int i=1; i<=N; i++){
        dp[1][i] = cost[1][i];
    }
    for(int i=2; i<=K; i++){
        solve(i, 1, N, 1, N);
    }
    cout << dp[K][N] << '\n';

    return 0;
}