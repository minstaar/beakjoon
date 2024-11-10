#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        ll x; cin >> x;
        ll n = sqrt(x);
        if(n * n == x) cout << 4 * n << '\n';
        else if(n * (n + 1) >= x) cout << 4 * n + 2 << '\n';
        else cout << 4 * n + 4 << '\n';
    }

    return 0;
}