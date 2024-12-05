#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, T, t[1010][1010];
int dp[1010][210];
vector<pii> arr;

int solve(int time, int idx)
{
    if(time < 0) return -1e9;
    if(time == 0){
        if(arr[idx].first == 0) return 0;
        else return -1e9;
    }
    int &ret = dp[time][idx];
    if(ret != -1) return ret;

    ret = solve(time - 1, idx) + arr[idx].second;

    for(int i=0; i<N; i++){
        if(idx == i) continue;
        int val = solve(time - t[i][idx], i);
        if(val >= arr[idx].first) ret = max(ret, val);
    }
    return ret;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> T;
    arr.resize(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cin >> t[i][j];
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, solve(T, i));
    cout << ans << '\n';

    return 0;
}