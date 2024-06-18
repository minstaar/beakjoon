#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    if(N % 2) cout << 0 << '\n';
    else{
        vector<int> dp(N+1);
        dp[0] = 1;
        dp[2] = 3;
        for(int i=4; i<=N; i+=2){
            dp[i] = dp[i-2] * 4 - dp[i-4];
        }
        cout << dp[N] << '\n';
    }

    return 0;
}