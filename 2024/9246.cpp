#include <iostream>
#include <vector>
using namespace std;

const int MAX = 65535;
typedef long long ll;

void update(vector<int>& tree, int node, int start, int end, int index, int diff)
{
    if(index < start || end < index) return;
    tree[node] += diff;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int query(vector<int>& tree, int node, int start, int end, int val)
{
    if(start == end) return start;
    int mid = start + end >> 1;
    if(tree[node*2] >= val){
        return query(tree, node * 2, start, mid, val);
    }
    else{
        return query(tree, node * 2 + 1, mid + 1, end, val - tree[node*2]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    ll ans = 0;
    vector<int> arr(N), tree(MAX*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<K-1; i++) update(tree, 1, 0, MAX, arr[i], 1);
    for(int i=K-1; i<N; i++){
        update(tree, 1, 0, MAX, arr[i], 1);
        ans += query(tree, 1, 0, MAX, (K + 1) / 2);
        update(tree, 1, 0, MAX, arr[i-K+1], -1);
    }
    cout << ans << '\n';

    return 0;
}