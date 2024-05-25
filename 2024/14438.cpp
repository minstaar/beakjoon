#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct SegTree
{
    const int sz = 1 << 17;
    int arr[1<<18];
    void add(int x, int val)
    {
        x |= sz;
        arr[x] = val;
    }
    void construct()
    {
        for(int i=sz-1; i>0; i--){
            arr[i] = min(arr[i<<1], arr[i<<1|1]);
        }
    }
    void update(int i, int val)
    {
        --i |= sz;
        arr[i] = val;
        while(i >>= 1){
            arr[i] = min(arr[i<<1], arr[i<<1|1]);
        }
    }
    int query(int l, int r)
    {
        --l |= sz, --r |= sz;
        int res = INF;
        while(l <= r){
            if(l & 1) res = min(res, arr[l++]);
            if(~r & 1) res = min(res, arr[r--]);
            l >>= 1, r >>= 1;
        }
        return res;
    }
}tree;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=(1<<17); i<(1<<18); i++){
        tree.add(i, INF);
    }
    for(int i=0; i<N; i++){
        int t; cin >> t;
        tree.add(i, t);
    }
    tree.construct();

    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        if(a == 1){
            int b, c; cin >> b >> c;
            tree.update(b, c);
        }
        if(a == 2){
            int b, c; cin >> b >> c;
            cout << tree.query(b, c) << '\n';
        }
    }

    return 0;
}