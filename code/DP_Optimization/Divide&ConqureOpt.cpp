//#13261
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int L, G;
ll C[8010], dp[810][8010], psum[8010];

ll c(int k, int j)
{
    return (psum[j] - psum[k]) * (j - k);
}

void solve(int t, int s, int e, int optl, int optr)
{
    if(s > e) return;
    int mid = (s + e) >> 1;
    int opt = mid;
    dp[t][mid] = INF;

    for(int k=optl; k<=min(optr, mid - 1); k++){
        ll val = dp[t-1][k] + c(k, mid);
        if(dp[t][mid] > val){
            dp[t][mid] = val;
            opt = k;
        }
    }

    solve(t, s, mid - 1, optl, opt);
    solve(t, mid + 1, e, opt, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> L >> G;
    for(int i=1; i<=L; i++) {
        cin >> C[i];
        psum[i] = psum[i-1] + C[i];
    }


    for(int i=1; i<=L; i++){
        dp[0][i] = psum[i] * i;
    }
    for(int i=1; i<min(G, L); i++){
        solve(i, 1, L, 1, L);
    }

    cout << dp[min(G - 1, L - 1)][L] << '\n';

    return 0;
}