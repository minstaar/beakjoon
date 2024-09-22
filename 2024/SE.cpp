#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x, y, c; cin >> x >> y >> c;
    double dist = sqrt(x * x + y * y);
    int ans = ceil(dist / c);
    if(ans == 1 && x * x + y * y != c * c) cout << "2\n";
    else cout << ans << '\n';

    return 0;
}