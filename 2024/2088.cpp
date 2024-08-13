#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9;
int dp[310][310];
string str;

int solve(int s, int e)
{
    if(s > e) return 0;
    if(s == e) return 1;

    int &ret = dp[s][e];
    if(ret != -1) return ret;
    ret = 0;

    for(int i=s; i<=e; i++){
        if(str[s] == str[i]){
            int left = solve(s+1, i-1);
            int right = solve(i, e);
            ret = (ret + 1LL * left * right % MOD) % MOD;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, str.length() - 1) << '\n';

    return 0;
}