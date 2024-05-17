#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void update(vector<ll>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    tree[node] += val;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, val);
        update(tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<int> arr(N+1);
    vector<ll> tree(N*4);
    vector<vector<ll>> dp(K+1, vector<ll>(N+1));
    for(int i=1; i<=N; i++) cin >> arr[i];

    update(tree, 1, 0, N, 0, 1);
    for(int i=1; i<=K; i++){
        for(int j=1; j<=N; j++){
            update(tree, 1, 0, N, arr[j], dp[i-1][j]);
            dp[i][j] = query(tree, 1, 0, N, 0, arr[j] - 1) % MOD;
        }
        tree = vector<ll>(N*4);
    }
    ll ans = 0;
    for(int i=1; i<=N; i++){
        ans = (ans + dp[K][i]) % MOD;
    }
    cout << ans << '\n';

    return 0;
}