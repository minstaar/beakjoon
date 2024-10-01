#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 100'000'000'000;
int N, K, S;
ll arr[200010], dp[200010][40];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> S;
    for(int i=1; i<=N; i++) cin >> arr[i];
    
    if(K >= 37) cout << "MEGA\n";
    else{
        dp[0][0] = S;
        for(int i=1; i<=N; i++){
            if(dp[i-1][0] > 0) dp[i][0] = dp[i-1][0] + arr[i];
            for(int j=1; j<=min(i, K); j++){
                if(dp[i-1][j] <= 0 && dp[i-1][j-1] <= 0) continue;
                
                if(dp[i-1][j] <= 0) dp[i][j] = dp[i-1][j-1] * 2;
                else if(dp[i-1][j-1] <= 0) dp[i][j] = dp[i-1][j] + arr[i];
                else dp[i][j] = max(dp[i-1][j] + arr[i], dp[i-1][j-1] * 2);
            }

            bool flag = false;
            for(int j=0; j<=min(i, K); j++){
                if(dp[i][j] > 0){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "-1\n";
                return 0;
            }
        }
        ll ans = -INF;
        for(int i=0; i<=K; i++) ans = max(ans, dp[N][i]);
        if(ans > INF) cout << "MEGA\n";
        else if(ans > 0) cout << ans << '\n';
        else cout << "-1\n";
    }
    return 0;
}