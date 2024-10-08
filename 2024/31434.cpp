#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, K;
int dp[110][5100];
vector<pii> arr(110);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0;
    for(int i=0; i<K; i++){
        for(int j=1; j<=5000; j++){
            if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + j);
            for(int k=0; k<N; k++){
                dp[i+1][j+arr[k].second] = max(dp[i+1][j+arr[k].second], dp[i][j] - arr[k].first);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=5000; i++) ans = max(ans, dp[K][i]);
    cout << ans << '\n';
    
    return 0;
}