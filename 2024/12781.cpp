#include <iostream>
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

bool isIntersect(pll &A, pll &B, pll &C, pll &D)
{
    int line1_2 = CCW(A, B, C) * CCW(A, B, D);
    int line2_1 = CCW(C, D, A) * CCW(C, D, B);

    if(line1_2 == 0 && line2_1 == 0){
        if(A > B) swap(A, B);
        if(C > D) swap(C, D);
        return A <= D && C <= B;
    }
    return line1_2 < 0 && line2_1 < 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pll A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;

    cout << isIntersect(A, B, C, D) << '\n';

    return 0;
}