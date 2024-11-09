#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int sz = 1 << 19;
ll tree[sz<<1];

void add(int x, int val)
{
    tree[x|sz] = val;
}

void construct()
{
    for(int i=sz-1; i>=0; i--){
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}

void update(int i, int val)
{
    i |= sz;
    tree[i] = val;
    while(i >>= 1){
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}

ll query(int l, int r)
{
    l |= sz, r |= sz;
    ll ret = 0;
    while(l <= r){
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        add(i, a);
    }
    construct();

    while(M--){
        int a; cin >> a;
        cout << query(0, a - 1) + 1 << ' ';
        update(a, 0);
    }

    return 0;
}