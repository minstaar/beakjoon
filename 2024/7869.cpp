#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.1415926535;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    double x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    double res;
    
    if(r1 + r2 <= d){
        res = 0;
    }
    else if(abs(r1 - r2) >= d){
        if(r1 > r2){
            res = r2 * r2 * PI;
        }
        else{
            res = r1 * r1 * PI;
        }
    }
    else{
        double theta1 = 2 * acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double theta2 = 2 * acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        
        res = 0.5 * r1 * r1 * (theta1 - sin(theta1)) + 0.5 * r2 * r2 * (theta2 - sin(theta2));
    }

    res = round(res * 1000) / 1000;
    cout << fixed << setprecision(3) << res << '\n';

    return 0;
}