#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

ll dp[20][20], fac[20];

ll solve(int n, int k)
{
    if(k == 0) return fac[n];
    if(n == 1 && k == 1) return 0;
    ll &ret = dp[n][k];
    if(ret) return ret;
    ret = solve(n, k - 1) - solve(n - 1, k - 1);
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fac[1] = 1;
    for(int i=2; i<=17; i++) fac[i] = fac[i-1] * i;
    
    int T; cin >> T;
    for(int i=1; i<=T; i++){
        int a, N, K; cin >> a >> N >> K;
        memset(dp, 0, sizeof(dp));
        cout << i << ' ' << solve(N, K) << '\n';
    }
    return 0;
}