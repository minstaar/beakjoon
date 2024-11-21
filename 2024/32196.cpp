#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, M, K, X, Y; cin >> N >> M >> K >> X >> Y;
    vector<pll> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end(), [&](pll &A, pll &B){
        return A.first * X - A.second * Y < B.first * X - B.second * Y;
    });
    ll res = K * X + K * Y;
    for(int i=0; i<M; i++){
        res += arr[i].first * X;
        res -= arr[i].second * Y;
    }
    cout << res << '\n';

    return 0;
}