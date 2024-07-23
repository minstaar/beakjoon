#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

ll arr[300010], sorted[300010];
map<ll, int> height;

struct SegmentTree{
    ll tree[1200010];
    void update(int node, int s, int e, int idx, int val){
        if(idx < s || idx > e) return;
        if(s == e){
            tree[node] += val;
            return;
        }
        int m = s + e >> 1;
        update(node<<1, s, m, idx, val), update(node<<1|1, m+1, e, idx, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    ll query(int node, int s, int e, int l, int r){
        if(l > e || r < s) return 0;
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        return query(node<<1, s, m, l, r) + query(node<<1|1, m+1, e, l, r);
    }
}lSeg, rSeg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + N);
    int h = 0;
    for(int i=0; i<N; i++){
        if(height.find(sorted[i]) == height.end()){
            height[sorted[i]] = ++h;
        }
    }

    lSeg.update(1, 0, N-1, height[arr[0]], 1);
    for(int i=2; i<N; i++) rSeg.update(1, 0, N-1, height[arr[i]], 1);
    ll res = 0;
    for(int i=1; i<N-1; i++){
        int cur = height[arr[i]];
        res += lSeg.query(1, 0, N-1, 0, cur-1) * rSeg.query(1, 0, N-1, 0, cur-1);
        lSeg.update(1, 0, N-1, cur, 1);
        rSeg.update(1, 0, N-1, height[arr[i+1]], -1);
    }

    cout << res << '\n';

    return 0;
}