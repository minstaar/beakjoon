#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int dp[2010][2010];

int comb(int n, int r)
{
    if(r == 0 || n == r) return 1;
    int &ret = dp[n][r];
    if(ret != -1) return ret;
    return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    string str; cin >> str;
    
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for(int i=0; i<str.length() - 1; i++){
        if(str[i] == '>' && str[i+1] == '<'){
            int l = i, r = i + 1;
            while(l >= 0 && r < str.length() && str[l] == '>' && str[r] == '<'){
                res = (res + comb(N - (r - l + 1), l)) % MOD;
                l--, r++;
            }
        }
    }
    cout << res << '\n';

    return 0;
}