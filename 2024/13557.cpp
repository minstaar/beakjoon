#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Node
{
    ll sum;
    ll max;
    ll leftMax;
    ll rightMax;
};

Node combine(Node& a, Node& b)
{
    Node res;
    res.sum = a.sum + b.sum;
    res.max = max({a.max, b.max, a.rightMax + b.leftMax});
    res.leftMax = max(a.leftMax, a.sum + b.leftMax);
    res.rightMax = max(b.rightMax, a.rightMax + b.sum);
    return res;
}

void init(vector<int>& arr, vector<Node>& tree, int node, int start, int end)
{
    if(start == end){
        tree[node] = {arr[start], arr[start], arr[start], arr[start]};
        return;
    }
    int mid = start + end >> 1;
    init(arr, tree, node * 2, start, mid);
    init(arr, tree, node * 2 + 1, mid + 1, end);
    tree[node] = combine(tree[node*2], tree[node*2+1]);
}

Node query(vector<Node>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return {0, -INF, -INF, -INF};
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    Node a = query(tree, node * 2, start, mid, left, right);
    Node b = query(tree, node * 2 + 1, mid + 1, end, left, right);
    return combine(a, b);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    vector<Node> tree(N*4);
    for(int i=0; i<N; i++) cin >> arr[i];
    init(arr, tree, 1, 0, N - 1);

    int Q; cin >> Q;
    while(Q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ll ans;
        if(y1 < x2){
            ans = 0;
            ans += query(tree, 1, 0, N - 1, x1, y1).rightMax;
            if(y1 + 1 < x2) ans += query(tree, 1, 0, N - 1, y1 + 1, x2 - 1).sum;
            ans += query(tree, 1, 0, N - 1, x2, y2).leftMax;
            cout << ans << '\n';
        }
        else{
            ll left, right;
            ans = query(tree, 1, 0, N - 1, x2, y1).max;
            
            left = query(tree, 1, 0, N - 1, x1, x2 - 1).rightMax;
            right = query(tree, 1, 0, N - 1, x2, y2).leftMax;
            ans = max(ans, left + right);

            left = query(tree, 1, 0, N - 1, x1, y1).rightMax;
            right = query(tree, 1, 0, N - 1, y1 + 1, y2).leftMax;
            ans = max(ans, left + right);

            
            left = query(tree, 1, 0, N - 1, x1, x2 - 1).rightMax;
            right = query(tree, 1, 0, N - 1, y1 + 1, y2).leftMax;
            ans = max(ans, left + query(tree, 1, 0, N - 1, x2, y1).sum + right);
            
            cout << ans << '\n';
        }
    }
    
    return 0;
}