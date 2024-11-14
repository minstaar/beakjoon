#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int N, K;
vector<pii> arr(30);
int dp[30][2];

int solve(int cur, int cnt)
{
    if(cur == N - 1) return 0;
    int &ret = dp[cur][cnt];
    if(ret != -1) return ret;

    ret = solve(cur + 1, cnt) + arr[cur].first;
    if(cur + 2 <= N - 1) ret = min(ret, solve(cur + 2, cnt) + arr[cur].second);
    if(cnt == 0 && cur + 3 <= N - 1) ret = min(ret, solve(cur + 3, 1) + K);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++) cin >> arr[i].first >> arr[i].second;
    cin >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    return 0;
}