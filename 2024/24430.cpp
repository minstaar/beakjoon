#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, arr[1010][1010], dp[1010][1010][2];
bool chk[1010][1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) cin >> arr[i][j];
    }
    int k; cin >> k;
    for(int i=0; i<k; i++){
        int y, x; cin >> y >> x;
        chk[y][x] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(dp[i-1][j][0] == dp[i][j-1][0]){
                if(dp[i-1][j][1] > dp[i][j-1][1]){
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = dp[i-1][j][1];
                }
                else{
                    dp[i][j][0] = dp[i][j-1][0];
                    dp[i][j][1] = dp[i][j-1][1];
                }
            }
            else if(dp[i-1][j][0] > dp[i][j-1][0]){
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
            else{
                dp[i][j][0] = dp[i][j-1][0];
                dp[i][j][1] = dp[i][j-1][1];
            }
            dp[i][j][0] += arr[i][j];
            if(chk[i][j]) dp[i][j][1]++;
        }
    }
    cout << dp[N][N][0] << ' ' << dp[N][N][1] << '\n';

    return 0;
}