#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, x, y, z; cin >> N >> x >> y >> z;

    auto cnt = [&](ll time){
        return time / x + time / y + time / z;
    };

    ll l = 0, r = 1e18;
    while(l <= r){
        ll m = l + (r - l) / 2;
        if(cnt(m) >= N) r = m - 1;
        else l = m + 1;
    }

    ll prev = cnt(l - 1);
    if(N - prev == 1){
        if(l % x == 0) cout << "A win\n";
        else if(l % y == 0) cout << "B win\n";
        else cout << "C win\n";
    }
    else if(N - prev == 2){
        if(l % x == 0 && l % y == 0) cout << "B win\n";
        else cout << "C win\n";
    }
    else cout << "C win\n";

    return 0;
}