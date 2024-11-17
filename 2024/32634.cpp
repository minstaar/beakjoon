#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M;
ll psum[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int t, k; cin >> t >> k;
        psum[t-k+1] += 1;
        psum[t+1] -= 1;
    }
    for(int i=1; i<=N; i++) psum[i] += psum[i-1];
    for(int i=1; i<=N; i++) psum[i] += psum[i-1];

    ll ans = 0;
    for(int i=1; i<=N; i++){
        ll t = psum[i] / i + (psum[i] % i != 0);
        ans = max(ans, t);
    }
    cout << ans << '\n';

    return 0;
}