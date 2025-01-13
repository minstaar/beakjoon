#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << abs((a + d) - (b + c)) << '\n';

    return 0;
}