#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Node
{
    int min;
    int index;
    bool operator<(const Node& other)const{
        if(min == other.min) return index < other.index;
        return min < other.min;
    }
};

Node init(vector<int>& arr, vector<Node>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = {arr[start], start};
    int mid = start + end >> 1;
    Node a = init(arr, tree, node * 2, start, mid);
    Node b = init(arr, tree, node * 2 + 1, mid + 1, end);
    return tree[node] = min(a, b);
}

void update(vector<Node>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    if(start == end) {
        tree[node] = {val, index};
        return;
    }
    int mid = start + end >> 1;
    update(tree, node * 2, start, mid, index, val);
    update(tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

Node query(vector<Node>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return {INF, INF};
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    Node a = query(tree, node * 2, start, mid, left, right);
    Node b = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return min(a, b);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Node> tree(N*4);
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(arr, tree, 1, 0, N - 1);

    int Q; cin >> Q;
    while(Q--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(tree, 1, 0, N - 1, b - 1, c);
        }
        if(a == 2){
            cout << query(tree, 1, 0, N - 1, b - 1, c - 1).index + 1 << '\n';
        }
    }

    return 0;
}