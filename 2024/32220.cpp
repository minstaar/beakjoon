#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
int N, K, arr[6010], dp[3010][2];

int solve(int cur, int flag)
{
    if(cur > N){
        if(cur <= N + 2 && flag) return 1;
        else return 0;
    }
    int &ret = dp[cur][flag];
    if(ret != -1) return ret;
    ret = 0;

    for(int i=0; i<K; i++){
        if(arr[cur + i] != 1) ret = (ret + solve(cur + i + 1, flag)) % MOD;
    }
    if(arr[cur + K] != 1) ret = (ret + solve(cur + K + 1, 1)) % MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0) << '\n';

    return 0; 
}