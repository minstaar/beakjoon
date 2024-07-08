#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct CHT{
    struct Line{
        ll m, b;
        int idx;
        Line(ll _m, ll _b, int _idx): m(_m), b(_b), idx(_idx) {}
        ll f(ll x){
            return m * x + b;
        }
    };

    vector<Line> lines;
    int pv;

    void init(){
        lines.clear();
        pv = 0;
    }

    bool check(const Line &a, const Line &b, const Line &c){
		return (double)(a.b - b.b) / (b.m - a.m) >= (double)(c.b - b.b) / (b.m - c.m);
	}

    void addLine(Line cur){
        if(lines.size() > pv && lines.back().m == cur.m){
			if(cur.b < lines.back().b) cur = lines.back();
            lines.pop_back();
		}
		while(lines.size() >= pv+2 && check(lines[lines.size()-2], lines.back(), cur)) lines.pop_back();
		lines.push_back(cur);
	}

    pair<ll, int> query(ll x){
		// if min query, then lines[pv].f(x) >= lines[pv+1].f(x)
		while(pv + 1 < lines.size() && lines[pv].f(x) <= lines[pv+1].f(x)) pv++;
		return {lines[pv].f(x), lines[pv].idx};
	}
};