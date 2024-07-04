#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, A, B;
int arr[110][4], dp[110][2][110][110];

int solve(int n, int i, int j, int k)
{
    if(n == N){
        if(i < B || k > A) return -INF;
        return 0;
    }

    int &ret = dp[i][j][k][n];
    if(ret > 0) return ret;
    ret = -INF;

    if(k < A) ret = max(ret, solve(n + 1, i, 0, k+1) + arr[n][3]);
    if(j == 0) ret = max(ret, solve(n + 1, i, 1, k) + arr[n][2]);
    ret = max(ret, solve(n + 1, i + 1, 0, k) + max(arr[n][0], arr[n][1]));

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> A >> B;
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0, 0) << '\n';
    
    return 0;
}