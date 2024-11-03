#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
int dp[100010][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, M; cin >> N >> M;

    for(int i=0; i<N; i++){
        int k, flag; cin >> k >> flag;
        if(flag){
            if(i == 0){
                dp[i][0] = M - 1;
                dp[i][1] = 1;
            }
            else{
                dp[i][0] = dp[i-1][0] * (M - 1) % MOD;
                dp[i][1] = dp[i-1][0] + dp[i-1][1] * (M - 1) % MOD;
                dp[i][1] %= MOD;
            }
        }
        else{
            if(i == 0){
                dp[i][0] = 1;
                dp[i][1] = M - 1;
            }
            else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] * (M - 1) % MOD + dp[i-1][1];
                dp[i][1] %= MOD;
            }
        }
    }
    cout << (dp[N-1][0] + dp[N-1][1]) % MOD << '\n';

    return 0;
}