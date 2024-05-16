#include <iostream>
#include <vector>
using namespace std;

void init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = start + end >> 1;
    init(arr, tree, node * 2, start, mid);
    init(arr, tree, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

void propagate(vector<int>& tree, vector<int>& lazy, int node, int start, int end)
{
    if(!lazy[node]) return;
    tree[node] ^= (end - start + 1) % 2 * lazy[node];
    if(start != end){
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void update_range(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int val)
{
    propagate(tree, lazy, node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        lazy[node] ^= val;
        propagate(tree, lazy, node, start, end);
        return;
    }
    int mid = start + end >> 1;
    update_range(tree, lazy, node * 2, start, mid, left, right, val);
    update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right)
{
    propagate(tree, lazy, node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return query(tree, lazy, node * 2, start, mid, left, right) ^ query(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N), tree(N*4), lazy(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(arr, tree, 1, 0, N - 1);

    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        if(a == 1){
            int b, c, k; cin >> b >> c >> k;
            update_range(tree, lazy, 1, 0, N - 1, b, c, k);
        }
        if(a == 2){
            int b, c; cin >> b >> c;
            cout << query(tree, lazy, 1, 0, N - 1, b, c) << '\n';
        }
    }

    return 0;
}