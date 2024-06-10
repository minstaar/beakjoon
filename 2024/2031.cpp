#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, N, D, K; cin >> T >> N >> D >> K;
    vector<int> arr(N+1);
    for(int i=1; i<=N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<vector<int>> dp(K+1, vector<int>(N+1));
    for(int i=1; i<=K; i++){
        for(int j=1; j<=N; j++){
            int idx = lower_bound(arr.begin(), arr.end(), arr[j] - D + 1) - arr.begin();
            if(idx == 0) dp[i][j] = j;
            else dp[i][j] = max(dp[i-1][idx-1] + j - idx + 1, dp[i][j-1]);
        }
    }
    cout << dp[K][N] << '\n';

    return 0;
}