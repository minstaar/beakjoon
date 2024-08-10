#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, W, arr[1010][2], dp[1010][1010];

int solve(int a, int b)
{
    if(a == W || b == W) return 0;
    
    int &ret = dp[a][b];
    if(ret != -1) return ret;
    
    int next = max(a, b) + 1;
    int distA, distB;
    if(a == 0) distA = abs(arr[next][0] - 1) + abs(arr[next][1] - 1);
    else distA = abs(arr[next][0] - arr[a][0]) + abs(arr[next][1] - arr[a][1]);
    if(b == 0) distB = abs(arr[next][0] - N) + abs(arr[next][1] - N);
    else distB = abs(arr[next][0] - arr[b][0]) + abs(arr[next][1] - arr[b][1]);
    
    ret = min(solve(next, b) + distA, solve(a, next) + distB);
    return ret;
}

void trace(int a, int b)
{
    if(a == W || b == W) return;
    int next = max(a, b) + 1;
    int distA, distB;
    if(a == 0) distA = abs(arr[next][0] - 1) + abs(arr[next][1] - 1);
    else distA = abs(arr[next][0] - arr[a][0]) + abs(arr[next][1] - arr[a][1]);
    if(b == 0) distB = abs(arr[next][0] - N) + abs(arr[next][1] - N);
    else distB = abs(arr[next][0] - arr[b][0]) + abs(arr[next][1] - arr[b][1]);
    
    if(dp[next][b] + distA < dp[a][next] + distB){
        cout << "1\n";
        trace(next, b);
    }
    else{
        cout << "2\n";
        trace(a, next);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> W;
    for(int i=1; i<=W; i++) cin >> arr[i][0] >> arr[i][1];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    trace(0, 0);

    return 0;
}