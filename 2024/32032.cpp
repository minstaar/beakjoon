#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, D; cin >> N >> D;
    ll mn = 0, mx = 0;
    for(int i=0; i<N; i++){
        ll t; cin >> t;
        mn = min(mn, t);
        mx = max(mx, t);
    }
    ll res = 0;
    ll a = -mn, b = mx;
    if(a > b) swap(a, b);
    if(mn == 0){
        res = mx * 2 + D;
    }
    else if(mx == 0){
        res = -mn * 2 + D;
    }
    else res = min({a * 2 + b * 2 + D * 2, a * 4 + b * 2 + D, a * 4 + b * 4 + max(0LL, D - a * 2 - b * 2)});
    cout << res << '\n';

    return 0;
}