#include <iostream>
#include <algorithm>
using namespace std;

int N, M, dp[100010], arr[100010], psum[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        psum[i] += psum[i-1] + arr[i];
    }

    dp[M] = psum[M];
    for(int i=M+1; i<=N; i++){
        dp[i] = max(dp[i-1] + arr[i], psum[i] - psum[i-M]);
    }
    cout << max(0, *max_element(dp + M + 1, dp + N + 1)) << '\n';

    return 0;
}