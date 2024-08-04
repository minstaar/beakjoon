#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;

int N, arr[510][2];
ll dp[510][510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i][0] >> arr[i][1];
    
    for(int i=1; i<N; i++){
        for(int j=1; j<=N-i; j++){
            dp[j][j+i] = 1e18;
            for(int k=j; k<=j+i-1; k++){
                dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + arr[j][0] * arr[k][1] * arr[j+i][1]);
            }
        }
    }
    cout << dp[1][N] << '\n';

    return 0;
}