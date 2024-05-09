#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll init(vector<ll>& diff, vector<ll>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = diff[start];
    else{
        int mid = start + end >> 1;
        return tree[node] = init(diff, tree, node * 2, start, mid) + init(diff, tree, node * 2 + 1, mid + 1, end);
    }
}

ll query(vector<ll>& diff, vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];

    int mid = start + end >> 1;
    return query(diff, tree, node * 2, start, mid, left, right) + query(diff, tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || end < index) return;
    tree[node] += val;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, val);
        update(tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<ll> arr(N), diff(N), tree(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    diff[0] = arr[0];
    for(int i=1; i<N; i++) diff[i] = arr[i] - arr[i-1];
    init(diff, tree, 1, 0, N-1);

    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        if(a == 1){
            int i, j, k; cin >> i >> j >> k;
            update(tree, 1, 0, N - 1, i - 1, k);
            update(tree, 1, 0, N - 1, j, -k);
        }
        if(a == 2){
            int x; cin >> x;
            cout << query(diff, tree, 1, 0, N - 1, 0, x - 1) << '\n';
        }
    }

    return 0;
}