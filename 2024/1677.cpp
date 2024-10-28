#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int path[110][110][110][8][3];

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
        if(tmp == 11){
            int abs = 1;
        }
        if(tmp == -1) continue;
        
        if(t1 + t2 + t3 == 1){
            if(t1 && B[j] == C[k]) tmp++;
            else if(t2 && A[i] == C[k]) tmp++;
            else if(t3 && A[i] == B[j]) tmp++;
        }
        else if(t1 + t2 + t3 == 0){
            if(A[i] == B[j] && B[j] == C[k]){
                tmp += 3;
            }
            else if(A[i] == B[j] || B[j] == C[k] || C[k] == A[i]) tmp++;
        }
        if(ret < tmp){
            path[i][j][k][state][0] = i + !t1;
            
            path[i][j][k][state][1] = i + !t2;
            
            path[i][j][k][state][2] = i + !t3;
        }
        ret = max(ret, tmp);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 0) << '\n';

    return 0;
}