#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<ll> arr(N+1), psum(N+1), dp(N+1);
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        psum[i] += psum[i-1] + arr[i];
    }
    dp[1] = max(0LL, psum[1]);
    for(int i=2; i<=N; i++){
        dp[i] = max(dp[i-1], psum[i] - dp[i-1]);
    }
    cout << dp[N] << '\n';

    return 0;
}