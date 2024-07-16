#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 9;
int N, M;
int dp[1010][1010];

int solve(int num, int k)
{
    if(num == 0 && k >= 0) return 1;
    else if(num < 0 || k < 0) return 0;
    int &ret = dp[num][k];
    if(ret != -1) return ret;
    ret = 0;
    ret = (ret + solve(num - 1, k - 1)) % MOD;
    ret = (ret + solve(num - 2, k - 1)) % MOD;
    ret = (ret + solve(num - 3, k - 1)) % MOD;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    memset(dp, -1, sizeof(dp));
    while(T--){
        cin >> N >> M;
        cout << solve(N, M) << '\n';
    }

    return 0;
}