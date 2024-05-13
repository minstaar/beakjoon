#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

void update(vector<ll>& tree, int node, int start, int end, int index, ll val)
{
    if(index < start || index > end) return;
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    update(tree, node * 2, start, mid, index, val);
    update(tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return -INF;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return max(query(tree, node * 2, start, mid, left, right), query(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<ll> arr(N), tree(N*4), dp(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    
    dp[0] = arr[0];
    for(int i=1; i<N; i++){
        update(tree, 1, 0, N - 1, i - 1, dp[i-1]);
        if(i >= K) dp[i] = query(tree, 1, 0, N - 1, i - K, i - 1);
        else dp[i] = query(tree, 1, 0, N - 1, 0, i);
        if(dp[i] < 0) dp[i] = 0;
        dp[i] += arr[i];
    }
    update(tree, 1, 0, N - 1, N - 1, dp[N - 1]);
    cout << query(tree, 1, 0, N - 1, 0, N - 1) << '\n';

    return 0;
}