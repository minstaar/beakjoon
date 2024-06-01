#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<vector<int>> arr(N+1, vector<int>(3));
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++) cin >> arr[i][j];
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(3, vector<int>(3, INF)));
    for(int i=0; i<3; i++) dp[1][i][i] = arr[1][i];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i != j){
                dp[2][i][j] = dp[1][j][j] + arr[2][i];
            }
        }
    }
    for(int i=3; i<=N; i++){
        for(int j=0; j<3; j++){
            dp[i][0][j] = min(dp[i-1][1][j], dp[i-1][2][j]) + arr[i][0];
            dp[i][1][j] = min(dp[i-1][0][j], dp[i-1][2][j]) + arr[i][1];
            dp[i][2][j] = min(dp[i-1][0][j], dp[i-1][1][j]) + arr[i][2];
        }
    }
    cout << min({dp[N][0][1], dp[N][0][2], dp[N][1][0], dp[N][1][2], dp[N][2][0], dp[N][2][1]}) << '\n';

    return 0;
}