#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, K, C, arr[11];
ll ans = 1e18;

bool check(ll t)
{
    ll sum = 0;
    for(int i=0; i<N; i++) sum += t / arr[i];
    return sum >= K;
}

void solve(int cur)
{
    if(cur == C){
        ll l = 0, r = 1e18;
        while(l <= r){
            ll m = l + r >> 1;
            if(check(m)) r = m - 1;
            else l = m + 1;
        }
        ans = min(ans, l);
        return;
    }
    bool flag = false;
    for(int i=0; i<N; i++){
        if(arr[i] == 1) continue;
        flag = true;
        arr[i]--;
        solve(cur + 1);
        arr[i]++;
    }
    if(!flag) ans = K / N + min(K % N, 1LL);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> C;
    for(int i=0; i<N; i++) cin >> arr[i];

    solve(0);
    cout << ans << '\n';

    return 0;
}