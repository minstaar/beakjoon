#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;
using pll = pair<ll, ll>;

pll extgcd(ll a, ll b)
{
    ll x0 = 1, y0 = 0;
    ll x1 = 0, y1 = 1;
    while(b){
        ll q = a / b;
        ll r = a % b;
        ll x = x0 - q * x1;
        ll y = y0 - q * y1;
        a = b, b = r;
        x0 = x1, x1 = x;
        y0 = y1, y1 = y;
    }
    return {x0, y0};
}

ll CRT(ll a1, ll m1, ll a2, ll m2)
{
    auto [x, y] = extgcd(m1, m2);
    ll ret = ((i128)a1 * m2 * y + (i128)a2 * m1 * x) % (m1 * m2);
    return ret < 0 ? ret + m1 * m2 : ret;
}

ll solve(ll d1, ll d2, ll d3, ll m[])
{
    ll tmp = CRT(d1, m[0], d2, m[1]);
    return CRT(tmp, m[0] * m[1], d3, m[2]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll m[3], x[3], y[3];
    for(int i=0; i<3; i++) cin >> m[i];
    for(int i=0; i<3; i++) cin >> x[i];
    for(int i=0; i<3; i++) cin >> y[i];

    ll res = 1e18;
    
    for(ll i=-y[0]; i<=y[0]; i++){
        for(ll j=-y[1]; j<=y[1]; j++){
            ll d1 = (x[0] + i) % m[0]; if(d1 < 0) d1 += m[0];
            ll d2 = (x[1] + j) % m[1]; if(d2 < 0) d2 += m[1];
            ll d3 = (x[2] - y[2]) % m[2]; if(d3 < 0) d3 += m[2];
            res = min(res, solve(d1, d2, d3, m));
        }
    }

    for(ll i=-y[0]; i<=y[0]; i++){
        for(ll j=-y[2]; j<=y[2]; j++){
            ll d1 = (x[0] + i) % m[0]; if(d1 < 0) d1 += m[0];
            ll d2 = (x[1] - y[1]) % m[1]; if(d2 < 0) d2 += m[1];
            ll d3 = (x[2] + j) % m[2]; if(d3 < 0) d3 += m[2];
            res = min(res, solve(d1, d2, d3, m));
        }
    }

    for(ll i=-y[1]; i<=y[1]; i++){
        for(ll j=-y[2]; j<=y[2]; j++){
            ll d1 = (x[0] - y[0]) % m[0]; if(d1 < 0) d1 += m[0];
            ll d2 = (x[1] + i) % m[1]; if(d2 < 0) d2 += m[1];
            ll d3 = (x[2] + j) % m[2]; if(d3 < 0) d3 += m[2];
            res = min(res, solve(d1, d2, d3, m));
        }
    }

    int cnt = 0;
    for(int i=0; i<3; i++){
        for(ll j=-y[i]; j<=y[i]; j++){
            if((x[i] + j) % m[i] == 0){
                cnt++;
                break;
            }
        }
    }

    if(cnt == 3) cout << 0 << '\n';
    else cout << res << '\n';

    return 0;
}