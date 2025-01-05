#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e6;
int N;
string str;
ll dp[5010];

ll solve(int cur)
{
    if(str[cur] == '0') return 0;
    if(cur == N) return 1;
    ll &ret = dp[cur];
    if(ret != -1) return ret;
    if(cur < N - 1 && str[cur+1] == '0') ret = solve(cur + 2) % MOD;
    else{
        ret = solve(cur + 1) % MOD;
        if(cur < N - 1 && (str[cur] == '1' || str[cur] == '2' && str[cur+1] <= '6')){
            ret = (ret + solve(cur + 2)) % MOD;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    N = str.size();

    if(str[0] == '0'){
        cout << "0\n";
        return 0;
    }
    for(int i=1; i<N; i++){
        if(str[i] == '0' && (str[i-1] == '0' || str[i-1] >= '3')){
            cout << "0\n";
            return 0;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0) << '\n';

    return 0;
}