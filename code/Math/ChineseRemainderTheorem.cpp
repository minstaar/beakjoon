#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> extgcd(ll a, ll b){
    pair<ll, ll> ca = {1, 0}, cb = {0, 1};
    while(b){
        ll q = a / b, r = a % b;
        pair<ll, ll> cr = {ca.first - q * cb.first, ca.second - q * cb.second};
        tie(ca, cb) = tie(cb, cr);
    }
    return ca;
}

ll CRT(ll a1, ll m1, ll a2, ll m2){
    auto [x, y] = extgcd(m1, m2);
    return (a1 * m2 * y + a2 * m1 * x) % (m1 * m2);
}