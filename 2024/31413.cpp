#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A, D, arr[2010];
int dp[2010][1010];


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    cin >> A >> D;

    for(int i=0; i<=N+D-1; i++){
        for(int j=0; j<=N; j++){
            dp[i][j] = -1e9;
        }
    }

    dp[0][0] = 0;
    for(int i=1; i<=N+D-1; i++){
        dp[i][0] = dp[i-1][0] + arr[i];
        if(i >= D){
            for(int j=1; j<=N; j++){
                dp[i][j] = max(dp[i-1][j] + arr[i], dp[i-D][j-1] + A);
            }
        }
    }
    
    bool flag = false;
    for(int i=0; i<=N; i++){
        if(dp[N+D-1][i] >= M){
            cout << i << '\n';
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1 << '\n';

    return 0;
}