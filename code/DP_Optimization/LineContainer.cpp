#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Line {
	mutable ll a, b, p;
	bool operator<(const Line& o) const { return a < o.a; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll INF = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool cross(iterator x, iterator y) {
		if (y == end()) return x->p = INF, 0;
		if (x->a == y->a) x->p = x->b > y->b ? INF : -INF;
		else x->p = div(y->b - x->b, x->a - y->a);
		return x->p >= y->p;
	}
	void add(ll a, ll b) { // y = ax + b; y = -ax -b for min query
		auto z = insert({a, b, 0}), y = z++, x = y;
		while (cross(y, z)) z = erase(z);
		if (x != begin() && cross(--x, y)) cross(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) cross(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.a * x + l.b;
	}
}CHT;