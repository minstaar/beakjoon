#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<vector<int>> arr(n+1, vector<int>(n+1));
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(3)));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=2; i<=n; i++){
        if(arr[1][i]) break;
        dp[1][i][0] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]) continue;
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
            if(arr[i-1][j]!=1 && arr[i][j-1]!=1) dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }

    cout<<dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}
