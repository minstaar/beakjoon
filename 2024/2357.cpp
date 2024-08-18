#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int arr[100010];
vector<pii> bucket(1010, {2e9, -2e9});
int sq;

pii query(int l, int r)
{
    pii ret = {2e9, -2e9};
    while(l % sq != 0 && l <= r){
        ret.first = min(ret.first, arr[l]);
        ret.second = max(ret.second, arr[l]);
        l++;
    }
    while((r + 1) % sq != 0 && l <= r){
        ret.first = min(ret.first, arr[r]);
        ret.second = max(ret.second, arr[r]);
        r--;
    }
    while(l <= r){
        ret.first = min(ret.first, bucket[l/sq].first);
        ret.second = max(ret.second, bucket[l/sq].second);
        l += sq;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> arr[i];
    sq = sqrt(N);
    for(int i=1; i<=N; i++){
        bucket[i/sq].first = min(bucket[i/sq].first, arr[i]);
        bucket[i/sq].second = max(bucket[i/sq].second, arr[i]);
    }

    while(Q--){
        int a, b; cin >> a >> b;
        pii res = query(a, b);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}