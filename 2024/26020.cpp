#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    string order = "cdhs";
    int len = str.length();
    ll res = 1e18;
    do{
        vector<vector<ll>> dp(len + 1, vector<ll>(4, 1e18));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for(int i=1; i<=len; i++){
            for(int j=0; j<4; j++){
                if(j > 0) dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + (str[i-1] != order[j]);
                else dp[i][j] = dp[i-1][j] + (str[i-1] != order[j]);
            }
        }
        res = min({res, dp[len][0], dp[len][1], dp[len][2], dp[len][3]});
    }while(next_permutation(order.begin(), order.end()));

    cout << res << '\n';

    return 0;
}