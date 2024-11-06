#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int CCW(pll &A, pll &B, pll &C)
{
    ll op = A.first * B.second + B.first * C.second + C.first * A.second;
    op -= B.first * A.second + C.first * B.second + A.first * C.second;

    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

void intersection(pll &A, pll &B, pll &C, pll &D)
{
    double x = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
    double y = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
    double div = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

    if(div == 0){
        if(B == C && A <= C){
            cout << B.first << ' ' << B.second << '\n';
        }
        else if(A == D && C <= A){
            cout << A.first << ' ' << A.second << '\n';
        }
    }
    else{
        cout << fixed << setprecision(9) << x / div << ' ' << y / div << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pll A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;

    int line1_2 = CCW(A, B, C) * CCW(A, B, D);
    int line2_1 = CCW(C, D, A) * CCW(C, D, B);

    if(line1_2 == 0 && line2_1 == 0){
        if(A > B) swap(A, B);
        if(C > D) swap(C, D);
        if(A <= D && C <= B){
            cout << "1\n";
            intersection(A, B, C, D);
        }
        else{
            cout << "0\n";
        }
    }
    else if(line1_2 <= 0 && line2_1 <= 0){
        cout << "1\n";
        intersection(A, B, C, D);
    }
    else cout << "0\n";

    return 0;
}