#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Node
{
    int l, r;
    ll sum;
    Node() {l = r = -1; sum = 0;}    
};
Node tree[4000000];
int pv = 1;

void update(int node, int start, int end, int index, ll val)
{
    if(start == end){
        tree[node].sum = val;
        return;
    }
    int mid = start + end >> 1;
    if(index <= mid){
        if(tree[node].l == -1) tree[node].l = pv++;
        update(tree[node].l, start, mid, index, val);
    }
    else{
        if(tree[node].r == -1) tree[node].r = pv++;
        update(tree[node].r, mid + 1, end, index, val);
    }
    ll a = tree[node].l != -1 ? tree[tree[node].l].sum : 0;
    ll b = tree[node].r != -1 ? tree[tree[node].r].sum : 0;
    tree[node].sum = a + b;
}

ll query(int node, int start, int end, int left, int right)
{
    if(node == -1) return 0;
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node].sum;
    int mid = start + end >> 1;
    return query(tree[node].l, start, mid, left, right) + query(tree[node].r, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(0, 0, N - 1, b - 1, c);
        }
        if(a == 0){
            if(b > c) swap(b, c);
            cout << query(0, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
    
    return 0;
}