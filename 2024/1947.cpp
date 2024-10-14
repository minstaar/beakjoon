#include <iostream>
using namespace std;

const int MOD = 1e9;
int N, dp[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    dp[1] = 0; dp[2] = 1;
    for(int i=3; i<=N; i++){
        dp[i] = 1LL * (i - 1) * (dp[i-1] + dp[i-2]) % MOD;
    }
    cout << dp[N] << '\n';

    return 0;
}