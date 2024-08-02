#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> extgcd(ll a, ll b){
    if(b == 0) return {1, 0};
    ll x, y;
    tie(x, y) = extgcd(b, a % b);
    return {y, x-(a/b)*y};
}

pair<ll, ll> extgcd(ll a, ll b){
    pair<ll, ll> ca = {1, 0}, cb = {0, 1};
    while(b){
        ll q = a / b, r = a % b;
        pair<ll, ll> cr = {ca.first - q * cb.first, ca.second - q * cb.second};
        tie(ca, cb) = tie(cb, cr);
    }
    return ca;
}