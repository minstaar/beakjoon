#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int dp[110][100010], V[110], W[110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> W[i] >> V[i];

    for(int i=1; i<=N; i++){
        for(int j=1; j<W[i]; j++) dp[i][j] = dp[i-1][j];
        for(int j=W[i]; j<=K; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
        }
    }
    cout << dp[N][K] << '\n';

    return 0;
}