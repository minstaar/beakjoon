#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int CCW(pll &A, pll &B, pll &C)
{
    ll op = A.first * B.second + B.first * C.second + C.first * A.second;
    op -= B.first * A.second + C.first * B.second + A.first * C.second;

    return (op > 0) - (op < 0);
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
    return line1_2 <= 0 && line2_1 <= 0;
}