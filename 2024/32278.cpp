#include <iostream>
using namespace std;
using ll = long long;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a; cin >> a;
    if(-32768 <= a && a <= 32767) cout << "short\n";
    else if(-2147483648 <= a && a <= 2147483647) cout << "int\n";
    else cout << "long long\n";

    return 0;
}