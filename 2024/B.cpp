#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int y1, m1, d1; double t1, p1; cin >> y1 >> m1 >> d1 >> t1 >> p1;
    int y2, m2, d2; double t2, p2; cin >> y2 >> m2 >> d2 >> t2 >> p2;

    int year1 = y1 * 12 * 30 + m1 * 30 + d1;
    int year2 = y2 * 12 * 30 + m2 * 30 + d2;

    if(year1 > year2){
        int tmp = year1 + year1 - year2;
        int y = tmp / (12 * 30);
        tmp %= 12 * 30;
        int m = tmp / 30;
        tmp %= 30;
        int d = tmp;
        if(m == 0){
            m = 12;
            y--;
        }
        if(d == 0){
            d = 30;
            m--;
            if(m == 0){
                m = 12;
                y--;
            }
        }
        cout << y << ' ' << m << ' ' << d << ' ';
    }
    else{
        int tmp = year1 - (year2 - year1);
        int y = tmp / (12 * 30);
        tmp %= 12 * 30;
        int m = tmp / 30;
        tmp %= 30;
        int d = tmp;
        if(m == 0){
            m = 12;
            y--;
        }
        if(d == 0){
            d = 30;
            m--;
            if(m == 0){
                m = 12;
                y--;
            }
        }
        cout << y << ' ' << m << ' ' << d << ' ';
    }

    cout << fixed;
    cout.precision(3);
    if(t1 > t2){
        double tmp = t1 + t1 - t2;
        cout << tmp << ' ';
    }
    else{
        double tmp = t1 - (t2 - t1);
        cout << tmp << ' ';
    }

    if(p1 > p2){
        double tmp = p1 + p1 - p2;
        cout << tmp << ' ';
    }
    else{
        double tmp = p1 - (p2 - p1);
        cout << tmp << ' ';
    }

    return 0;
}