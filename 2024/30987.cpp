#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll p, q; cin >> p >> q;
    ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;

    auto func = [&] (ll x){
        ll res1 = a / 3 * x * x * x + b / 2 * x * x + c * x;
        ll res2 = d / 2 * x * x + e * x;
        return res1 - res2;
    };

    cout << func(q) - func(p) << '\n';

    return 0;
}