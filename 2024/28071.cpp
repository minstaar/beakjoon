#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> arr(310);
vector<vector<int>> dp(310, vector<int>(310, -1e9));

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++) cin >> arr[i];

    dp[0][0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<K; k++){
                int tmp = dp[j][k] + arr[i];
                dp[j+1][tmp%K] = max(dp[j+1][tmp%K], tmp);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=M; i++) ans = max(ans, dp[i][0]);
    cout << ans << '\n';

    return 0;
}