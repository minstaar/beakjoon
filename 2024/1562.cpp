#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(10, vector<int>(1050, 0)));
    for(int i=0; i<10; i++) dp[1][i][(1<<i)] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                if(j == 0){
                    dp[i][j][k | (1<<j)] = dp[i-1][j+1][k];
                }
                if(j >= 1 && j <= 8){
                    dp[i][j][k | (1<<j)] = (dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
                }
                if(j == 9){
                    dp[i][j][k | (1<<j)] = dp[i-1][j-1][k];
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=9; i++){
        ans = (ans + dp[n][i][1023]) % MOD;
    }
    cout<<ans;
    return 0;
}
