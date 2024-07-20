#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;

int dp[110][110][110];
string S, A, B, C;

int solve(int i, int j, int k)
{
    if(A.length() == i && B.length() == j && C.length() == k) return 1;

    int &ret = dp[i][j][k];
    if(ret != -1) return ret;
    ret = 0;
    
    int pos = i + j + k;

    if (i < A.length() && S[pos] == A[i]) ret = (ret + solve(i + 1, j, k)) % MOD;
    if (j < B.length() && S[pos] == B[j]) ret = (ret + solve(i, j + 1, k)) % MOD;
    if (k < C.length() && S[pos] == C[k]) ret = (ret + solve(i, j, k + 1)) % MOD;
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> A >> B >> C >> S;
    cout << solve(0, 0, 0) << '\n';

    return 0;
}