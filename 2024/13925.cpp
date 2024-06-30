#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

struct SegmentTree{
    ll arr[100010], tree[400010], lazy[400010][2];

    void init(int node, int start, int end){
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = start + end >> 1;
        init(node<<1, start, mid);
        init(node<<1|1, mid+1, end);
        tree[node] = (tree[node<<1] + tree[node<<1|1]) % MOD;
    }

    void propagate(int node, int start, int end){
        if(lazy[node][1] == 1 && lazy[node][0] == 0) return;
        tree[node] *= lazy[node][1]; tree[node] %= MOD;
        tree[node] += (end - start + 1) * lazy[node][0]; tree[node] %= MOD;
        if(start ^ end){
            lazy[node<<1][1] *= lazy[node][1]; lazy[node<<1][1] %= MOD;
            lazy[node<<1][0] *= lazy[node][1]; lazy[node<<1][0] %= MOD;
            lazy[node<<1][0] += lazy[node][0]; lazy[node<<1][0] %= MOD;
        
            lazy[node<<1|1][1] *= lazy[node][1]; lazy[node<<1|1][1] %= MOD;
            lazy[node<<1|1][0] *= lazy[node][1]; lazy[node<<1|1][0] %= MOD;
            lazy[node<<1|1][0] += lazy[node][0]; lazy[node<<1|1][0] %= MOD;
        }
        lazy[node][1] = 1, lazy[node][0] = 0;
    }

    void update_range(int node, int start, int end, int left, int right, ll a, ll b){
        propagate(node, start, end);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[node][1] *= a; lazy[node][1] %= MOD;
            lazy[node][0] *= a; lazy[node][0] %= MOD;
            lazy[node][0] += b; lazy[node][0] %= MOD;
            propagate(node, start, end);
            return;
        }
        int mid = start + end >> 1;
        update_range(node<<1, start, mid, left, right, a, b);
        update_range(node<<1|1, mid+1, end, left, right, a, b);
        tree[node] = (tree[node<<1] + tree[node<<1|1]) % MOD;
    }

    ll query(int node, int start, int end, int left, int right){
        propagate(node, start, end);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[node];
        int mid = start + end >> 1;

        ll a = query(node<<1, start, mid, left, right);
        ll b = query(node<<1|1, mid+1, end, left, right);
        return (a + b) % MOD;
    }
}seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> seg.arr[i];
    for(int i=0; i<400010; i++) seg.lazy[i][1] = 1;
    seg.init(1, 0, N-1);
    int Q; cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int x, y, v; cin >> x >> y >> v;
            seg.update_range(1, 0, N-1, x-1, y-1, 1, v);
        }
        if(op == 2){
            int x, y, v; cin >> x >> y >> v;
            seg.update_range(1, 0, N-1, x-1, y-1, v, 0);
        }
        if(op == 3){
            int x, y, v; cin >> x >> y >> v;
            seg.update_range(1, 0, N-1, x-1, y-1, 0, 0);
            seg.update_range(1, 0, N-1, x-1, y-1, 1, v);
        }
        if(op == 4){
            int x, y; cin >> x >> y;
            cout << seg.query(1, 0, N-1, x-1, y-1) << '\n';
        }
    }

    return 0;
}