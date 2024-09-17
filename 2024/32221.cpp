#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
int N, K;
bool arr[1000010];
ll dp[1000010][2], psum[1000010][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=2; i<=N+1; i++) cin >> arr[i];

    dp[0][0] = psum[0][0] = 1;
    for(int i=1; i<=N+1; i++){
        if(i <= K){
            dp[i][0] = psum[i-1][0];
            dp[i][1] = psum[i-1][1];
        }
        else{
            dp[i][0] = (psum[i-1][0] - psum[i-K-1][0] + MOD) % MOD;
            dp[i][1] = (psum[i-1][1] - psum[i-K-1][1] + MOD) % MOD;
        }
        if(i - K >= 1 && arr[i-K] != 1){
            dp[i][1] = (dp[i][1] + dp[i-K-1][0]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-K-1][1]) % MOD;
        }
        psum[i][0] = psum[i-1][0], psum[i][1] = psum[i-1][1];
        if(arr[i+1] != 1){
            psum[i][0] = (psum[i][0] + dp[i][0]) % MOD;
            psum[i][1] = (psum[i][1] + dp[i][1]) % MOD;
        }
    }

    cout << dp[N+1][1] << '\n';

    return 0; 
}