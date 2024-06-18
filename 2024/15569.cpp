#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1999;
    
int pow2(int x)
{
    int res = 1;
    for(int i=1; i<=x; i++){
        res *= 2;
        res %= MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> dp(M+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=M; i++){
        for(int j=1; j<N; j++){
            if(i - j >= 0)dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
        if(i >= N)dp[i] = (dp[i] + dp[i-N] * pow2(N - 1)) % MOD;
    }
    cout << dp[M] << '\n';

    return 0;
}