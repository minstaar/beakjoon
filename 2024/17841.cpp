#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
int N, dp[100010][30];
vector<string> str(100010);

int solve(int cur, int i)
{
    if(cur == N){
        if(i == 5) return 1;
        else return 0;
    }
    int &ret = dp[cur][i];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(cur + 1, i) % MOD;
    for(int k=0; k<str[cur].length(); k++){
        if("UNIST"[i+k] == str[cur][k]){
            ret += solve(cur + 1, i + k + 1);
            ret %= MOD;
        }
        else break;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> str[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}