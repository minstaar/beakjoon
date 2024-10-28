#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
string A, B, C;
int dp[110][110][110][8];

int solve(int i, int j, int k, int state)
{
    if(i >= A.size() && j >= B.size() && k >= C.size()) return 0;
    
    int &ret = dp[i][j][k][state];
    if(dp[i][j][k][state] != -1) return ret;

    int s1 = state & 1, s2 = (state >> 1) & 1, s3 = (state >> 2) & 1;
    for(int l=0; l<7; l++){
        int t1 = l & 1, t2 = (l >> 1) & 1, t3 = (l >> 2) & 1;
        if((s1 && t1) || (s2 && t2) || (s3 && t3)) continue;
        if(i >= A.size() && !t1 || j >= B.size() && !t2 || k >= C.size() && !t3) continue;

        int tmp = solve(i + !t1, j + !t2, k + !t3, l);

        if(tmp == -INF) continue;
        
        if(t1 + t2 + t3 == 1){
            if(t1 && j < B.size()  && k < C.size() && B[j] == C[k]) tmp++;
            else if(t2 &&  i < A.size() && k < C.size() && A[i] == C[k]) tmp++;
            else if(t3 && i < A.size() && j < B.size() && A[i] == B[j]) tmp++;
        }
        else if(t1 + t2 + t3 == 0){
            if(i < A.size() && j < B.size() && k < C.size() && A[i] == B[j] && B[j] == C[k]) tmp += 3;
        }
        ret = max(ret, tmp);
    }

    if(ret == -1) return ret = -INF;
    else return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;
    memset(dp, -1, sizeof(dp));
    int res = solve(0, 0, 0, 0);
    if(res == -INF) cout << "-1\n";
    else cout << res << '\n';

    return 0;
}