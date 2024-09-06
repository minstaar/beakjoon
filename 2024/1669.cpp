#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b; cin >> a >> b;
    int diff = b - a;
    int n = sqrt(diff);
    int ans;

    if(diff == 0) ans = 0;
    else if(n * n == diff) ans = 2 * n - 1;
    else{
        if(n * (n + 1) >= diff) ans = 2 * n;
        else ans = 2 * n + 1;
    }

    cout << ans << '\n';

    return 0;
}