#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, arr[30], dp[30];

int solve(int cur)
{
    if(cur > N) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = solve(cur + 1);
    int tmp = 0;
    for(int i=cur; i<=N; i++){
        tmp += arr[i];
        if(tmp >= K){
            ret = max(ret, solve(i + 1) + tmp - K);
            break;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(1) << '\n';

    return 0;
}