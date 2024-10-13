#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<string> pat;
vector<vector<int>> fail;
int dp[100010], mem[510];

vector<int> getPi(string &s)
{
    int N = s.size(), j = 0;
    vector<int> pi(N);
    for(int i=1; i<N; i++){
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) pi[i] = ++j;
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;
    s = "$" + s;
    int N, K; cin >> K;
    N = s.size();
    pat.resize(K), fail.resize(K);
    for(int i=0; i<K; i++){
        cin >> pat[i];
        fail[i] = getPi(pat[i]);
    }

    for(int i=1; i<N; i++){
        dp[i] = dp[i-1];
        for(int j=0; j<K; j++){
            int pv = mem[j];
            while(pv && s[i] != pat[j][pv]) pv = fail[j][pv-1];
            if(s[i] == pat[j][pv]){
                if(pv == pat[j].size() - 1){
                    dp[i] = max(dp[i], dp[i-pat[j].size()] + (int)pat[j].size());
                    pv = fail[j][pv];
                }
                else pv++;
            }
            mem[j] = pv;
        }
    }

    cout << dp[N-1] << '\n';

    return 0;
}