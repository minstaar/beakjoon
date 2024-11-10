#include <iostream>
#include <vector>
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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pll A, B, C;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
    cout << CCW(A, B, C) << '\n';

    return 0;
}