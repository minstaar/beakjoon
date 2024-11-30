#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[310], dp[310][310][310];

int solve(int cur, int used, int mod)
{
    if(cur == N) return (mod == 0 ? 0 : -1e9);
    if(used > M) return -1e9;

    int &ret = dp[cur][used][mod];
    if(ret != -1) return ret;
    
    ret = solve(cur + 1, used, mod);
    ret = max(ret, solve(cur, used + 1, (mod + arr[cur]) % K) + arr[cur]);
    
    return ret;
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for (int i=0; i<N; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << max(0, solve(0, 0, 0)) << '\n';

    return 0;
}
