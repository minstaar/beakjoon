#include <iostream>
using namespace std;
using ll = long long;

ll modinv(ll x, ll n)
{
    ll a = n, b = 0;
    ll c = x % n, d = 1;
    while(c){
        ll q = a / c;
        ll e = a - q * c, f = (b - q * d) % n;
        a = c, b = d;
        c = e, d = f;
    }
    if(a == 1) return (b + n) % n;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, x; cin >> n >> x;
    cout << n - x << ' ' << modinv(x, n) << '\n';

    return 0;
}