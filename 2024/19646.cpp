#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(200010), tree(800010);

void init(int node, int s, int e)
{
    if(s == e){
        tree[node] = arr[s];
        return;
    }
    int m = s + e >> 1;
    init(node * 2, s, m), init(node * 2 + 1, m + 1, e);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(int node, int s, int e, int idx, int val)
{
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node] = val;
        return;
    }
    int m = s + e >> 1;
    update(node * 2, s, m, idx, val), update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree[node];
    int m = s + e >> 1;
    return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    init(1, 0, N - 1);
    for(int i=0; i<N; i++){
        int p; cin >> p;
        int s = 0, e = N - 1;
        int res = 0;
        while(s <= e){
            int m = s + e >> 1;
            int t = query(1, 0, N - 1, 0, m);
            if(t < p) s = m + 1;
            else{
                res = m;
                e = m - 1;
            }
        }
        cout << res + 1 << ' ';
        update(1, 0, N - 1, res, 0);
    }
    
    return 0;
}