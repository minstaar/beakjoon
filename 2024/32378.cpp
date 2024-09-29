#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 100'000'000'000;
ll N, K, S;
ll arr[200010], dp[210][210];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> S;
    for(int i=1; i<=N; i++) cin >> arr[i];
    dp[0][0] = S;
    for(int i=1; i<=N; i++){
        dp[i][0] = dp[i-1][0] + arr[i];
        for(int j=1; j<=K; j++){
            dp[i][j] = max(dp[i-1][j] + arr[i], dp[i-1][j-1] * 2);
        }
    }
    ll ans = -INF;
    for(int i=0; i<=K; i++) ans = max(ans, dp[N][i]);

    cout << ans << '\n';

    return 0;
}