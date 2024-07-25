#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, X, K, arr[200010];
bool check[200010];
vector<int> dp(200010, INF), tree(800010, INF);

void update(int node, int s, int e, int idx, int val)
{
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node] = val;
        return;
    }
    int m = s + e >> 1;
    update(node<<1, s, m, idx, val), update(node<<1|1, m+1, e, idx, val);
    tree[node] = min(tree[node<<1], tree[node<<1|1]);
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s) return INF;
    if(l <=s && e <= r) return tree[node];
    int m = s + e >> 1;
    return min(query(node<<1, s, m, l, r), query(node<<1|1, m+1, e, l, r));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, X, K; cin >> N >> X >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(arr[i] == 0) cnt++;
        else cnt = 0;
        if(cnt >= K) check[i] = true;
    }

    for(int i=0; i<N-1; i++){
        if(check[i]){
            if(i < X) dp[i] = 1;
            else dp[i] = query(1, 0, N-1, max(0, i-X), max(0, i-K)) + 1;
            update(1, 0, N-1, i, dp[i]);
        }
    }
    dp[N-1] = query(1, 0, N-1, N-X-1, N-2) + 1;
    if(dp[N-1] >= INF) cout << -1 << '\n';
    else cout << dp[N-1] << '\n';

    return 0;
}