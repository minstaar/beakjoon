#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sqrtN;

struct Query{
	int idx, s, e;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

vector<Query> query;
vector<int> arr;
ll ans[100010];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, Q; cin >> N >> Q;
    sqrtN = sqrt(N);
	arr.resize(N+1);

	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i=0; i<Q; i++){
		int s, e; cin >> s >> e;
		query.push_back({i, s, e});
	}
	sort(query.begin(), query.end());

	int s = query[0].s, e = query[0].e;
    ll res = 0;
	for(int i=s; i<=e; i++){
		res += arr[i];
	}
	ans[query[0].idx] = res;

	for(int i=1; i<Q; i++){
		while(s < query[i].s) res -= arr[s++];
		while(s > query[i].s) res += arr[--s];
		while(e < query[i].e) res += arr[++e];
		while(e > query[i].e) res -= arr[e--];
		ans[query[i].idx] = res;
	}
	for(int i=0; i<Q; i++) cout << ans[i] << "\n";

    return 0;
}