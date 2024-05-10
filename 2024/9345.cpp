#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Node
{
    int min;
    int max;
};

Node init(vector<int>& arr, vector<Node>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = {arr[start], arr[start]};
    
    int mid = start + end >> 1;
    Node a = init(arr, tree, node * 2, start, mid);
    Node b = init(arr, tree, node * 2 + 1, mid + 1, end);
    tree[node].min = min(a.min, b.min);
    tree[node].max = max(a.max, b.max);
    return tree[node];
}

Node update(vector<Node>& tree, int node, int start, int end, int index, int k)
{
    if(index < start || end < index) return tree[node];
    
    if(start == end){
        tree[node].min = k;
        tree[node].max = k;
        return tree[node];
    }
    else {
        int mid = start + end >> 1;
        Node a = update(tree, node * 2, start, mid, index, k);
        Node b = update(tree, node * 2 + 1, mid + 1, end, index, k);
        tree[node].min = min(a.min, b.min);
        tree[node].max = max(a.max, b.max);
        return tree[node];
    }
}

Node query(vector<Node>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return {INF, -INF};
    if(left <= start && end <= right) return tree[node];

    int mid = start + end >> 1;
    Node a = query(tree, node * 2, start, mid, left, right);
    Node b = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return {min(a.min, b.min), max(a.max, b.max)};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        vector<int> arr(N);
        vector<Node> tree(N*4);
        for(int i=0; i<N; i++) arr[i] = i;
        init(arr, tree, 1, 0, N-1);
        for(int i=0; i<K; i++){
            int q; cin >> q;
            if(q == 0){
                int a, b; cin >> a >> b;
                int tmp = arr[a];
                arr[a] = arr[b];
                update(tree, 1, 0, N-1, a, arr[b]);
                arr[b] = tmp;
                update(tree, 1, 0, N-1, b, tmp);
            }
            if(q == 1){
                int a, b; cin >> a >> b;
                Node c = query(tree, 1, 0, N-1, a, b);
                if(c.min == a && c.max == b) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }

    return 0;
}