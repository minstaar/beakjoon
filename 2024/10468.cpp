#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, arr[210], dp[210][210];

int solve(int l, int r)
{
    if(l + 1 == r) return 0;
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    for(int i=l+1; i<=r-1; i++){
        ret = max(ret, solve(l, i) + solve(i, r) + arr[l] + arr[i] + arr[r]);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        cin >> N;
        if(N == 0) break;
        for(int i=0; i<N; i++) cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        cout << solve(0, N-1) << '\n';
    }

    return 0;
}