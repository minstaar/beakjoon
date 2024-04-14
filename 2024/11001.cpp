#include <iostream>
#include <vector>
using namespace std;

int N, D;
long long cnt, ans;
vector<long long> T, V, dp;

void solve(int s, int e, int optl, int optr)
{
    if(s > e) return;
    int mid = (s + e) >> 1;
    int opt = mid;
    dp[mid] = V[mid];

    for(int i=optl; i<=min(optr, mid+D); i++){
        long long val = (i - mid) * T[i] + V[mid];
        if(dp[mid] < val){
            dp[mid] = val;
            opt = i;
        }
    }

    solve(s, mid - 1, optl, opt);
    solve(mid + 1, e, opt, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> D;
    T.resize(N + 1), V.resize(N + 1), dp.resize(N + 1);
    for(int i=1; i<=N; i++) cin >> T[i];
    for(int i=1; i<=N; i++) cin >> V[i];

    solve(1, N, 1, N);

    for(int i=1; i<=N; i++) ans = max(ans, dp[i]);
    cout << ans <<'\n';

    return 0;
}