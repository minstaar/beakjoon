#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 9901;
int N, M, dp[15*15][1<<14];

int solve(int k, int state)
{
    if(k == N * M && !state) return 1;
    if(k >= N * M) return 0;
    int& res = dp[k][state];
    if(res != -1) return res;
    res = 0;

    if(state & 1) res = solve(k + 1, state >> 1);
    else{
        if((k % M) != (M - 1) && !(state & 2)){
            res += solve(k + 2, state >> 2);
        }
        res += solve(k + 1, (state >> 1) | (1 << (M - 1)));
    }
    return res % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}