#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double X, Y, D, T; cin >> X >> Y >> D >> T;

    double dist = sqrt(X * X + Y * Y);
    int div = dist / D;
    double rem = dist - D * div;

    double t1 = rem + div * T;
    double t2;
    if(div > 0){
        t2 = (div + 1) * T;
    }
    else t2 = min(D - rem + T, T * 2);

    cout << fixed << setprecision(9) << min(dist, min(t1, t2)) << '\n';

    return 0;
}