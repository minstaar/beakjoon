#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
int N, K, arr[3010], dp[3010][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> arr[i];

    dp[0][1] = dp[1][0] = dp[K][1] = 1;
    for(int i=2; i<=N; i++){
        dp[i][0] = 1;
        if(arr[i] != 1){
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][1];
        }
        for(int j=i-2; j>=i-K && j>=1; j--){
            if(arr[j+1] != 1) dp[i][0] = (dp[i][0] + dp[j][0]) % MOD;
            if(arr[j+1] != 1) dp[i][1] = (dp[i][1] + dp[j][1]) % MOD;
        }
        if(i - K - 1 >= 0 && arr[i-K] != 1){
            dp[i][1] = (dp[i][1] + dp[i-K-1][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-K-1][0]) % MOD;
        }
    }

    cout << dp[N][1];

    return 0; 
}