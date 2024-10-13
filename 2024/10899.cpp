#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int P, N; cin >> P >> N;
    vector<ll> arr(N+1), psum(N+1);
    for(int i=1; i<=N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    psum[1] = arr[1];
    for(int i=2; i<=N; i++) psum[i] += psum[i-1] + arr[i];
    
    int idx = lower_bound(psum.begin(), psum.end(), P) - psum.begin() - 1;
    ll res = 1LL * (P - 1 - psum[idx]) * idx;
    ll sum = 0;
    for(int i=idx; i>=1; i--){
        sum += arr[i];
        res += sum;
    }
    cout << idx << ' ' << res << '\n';

    return 0;
}
