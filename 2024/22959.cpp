#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Node
{
    ll min;
    ll sum;
};

Node init(vector<ll>& arr, vector<Node>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = {arr[start], arr[start]};
    int mid = start + end >> 1;
    Node a = init(arr, tree, node * 2, start, mid);
    Node b = init(arr, tree, node * 2 + 1, mid + 1, end);
    tree[node].sum = a.sum + b.sum;
    tree[node].min = min(a.min, b.min);
    return tree[node];
}

Node update(vector<Node>& tree, int node, int start, int end, int index, ll val)
{
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = {val, val};

    int mid = start + end >> 1;
    Node a = update(tree, node * 2, start, mid, index, val);
    Node b = update(tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node].sum = a.sum + b.sum;
    tree[node].min = min(a.min, b.min);
    return tree[node];
}

ll Find(vector<Node>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return INF;
    if(left <= start && end <= right) return tree[node].min;
    int mid = start + end >> 1;
    return min(Find(tree, node * 2, start, mid, left, right), Find(tree, node * 2 + 1, mid + 1, end, left, right));
}

ll Sum(vector<Node>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node].sum;
    int mid = start + end >> 1;
    return Sum(tree, node * 2, start, mid, left, right) + Sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<ll> arr(N);
    vector<Node> tree(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(arr, tree, 1, 0, N - 1);

    int Q; cin >> Q;
    while(Q--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(tree, 1, 0, N - 1, b - 1, c);
        }
        if(a == 2){
            b--;
            pair<int, int> range;
            int left = 0, right = b;
            while(left <= right){
                int mid = left + right >> 1;
                ll min = Find(tree, 1, 0, N - 1, mid, b);
                if(min >= c){
                    range.first = mid;
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            left = b; right = N - 1;
            while(left <= right){
                int mid = left + right >> 1;
                ll min = Find(tree, 1, 0, N - 1, b, mid);
                if(min >= c){
                    range.second = mid;
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            cout << Sum(tree, 1, 0, N - 1, range.first, range.second) << '\n';
        }
    }

    return 0;
}