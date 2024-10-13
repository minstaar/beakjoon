#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 9;
int N;
string s;
ll dp[110][110];
int pi[110];

void getPi(string &s)
{
    int j = 0;
    for(int i=1; i<s.size(); i++){
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) pi[i] = ++j;
    }
}

ll solve(int i, int j)
{
    if(i == N){
        if(j == s.size()) return 1;
        else return 0;
    }
    ll &ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 0;
    for(int k=0; k<26; k++){
        if(j == s.size()){
            ret = (ret + solve(i + 1, j)) % MOD;
        }
        else{
            int pv = j;
            while(pv && 'a' + k != s[pv]) pv = pi[pv-1];
            if('a' + k == s[pv]){
                ret = (ret + solve(i + 1, pv + 1)) % MOD;
            }
            else{
                ret = (ret + solve(i + 1, 0)) % MOD;
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> s;
    getPi(s);
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}
