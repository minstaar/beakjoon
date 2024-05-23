#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
int N, M, dp[301][1<<18];

int solve(int k, int state)
{
    if(k == N * M) return 1;
    int& res = dp[k][state];
    if(res != -1) return res;

    res = solve(k + 1, state >> 1) % MOD;
    if(k % M == 0){
        res += solve(k + 1, (state >> 1) | (1 << M)) % MOD;
    }
    else if(!(state & (1 << M)) || !(state & 2) || !(state & 1)){
        res += solve(k + 1, (state >> 1) | (1 << M)) % MOD;
    }
    
    return res % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    if(N < M) swap(N, M);
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}