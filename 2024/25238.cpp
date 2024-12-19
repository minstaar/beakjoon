#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double a, b; cin >> a >> b;
    cout << (a - a * (b / 100) >= 100 ? 0 : 1) << '\n';
    return 0;
}