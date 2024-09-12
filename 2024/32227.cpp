#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        ll a, b, c; cin >> a >> b >> c;
        ll sum = abs(a) + abs(b) + abs(c);
        if(sum % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0; 
}