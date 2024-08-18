#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, sq, arr[1000010];
ll bucket[1010];

void init()
{
	sq = sqrt(N);
	for(int i=1; i<=N; i++){
		bucket[i/sq] += arr[i];
	}
}

void update(int idx, int val){
	arr[idx] = val;
	int id = idx/sq, s = id * sq, e = s + sq;
    bucket[id] = 0;
	for(int i=s; i<e; i++) bucket[id] += arr[i];
}

ll query(int l, int r){
	ll ret = 0;
	while(l % sq != 0 && l <= r) ret += arr[l++];
	while((r + 1) % sq != 0 && l <= r) ret += arr[r--];

	while(l <= r){
		ret += bucket[l/sq];
		l += sq;
	}

	return ret;
}