#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;

int N, X;
int arr[100010], dp[100010];
struct Node{
    int l, r, mx;
    Node(): l(-1), r(-1), mx(-1e9) {}
};
vector<Node> tree;
int pv;

void update(int node, ll s, ll e, ll idx, int val)
{
    if(s == e){
        tree[node].mx = val;
        return;
    }
    ll m = s + e >> 1;
    if(idx <= m){
        if(tree[node].l == -1) {tree[node].l = pv++; tree.emplace_back();}
        update(tree[node].l, s, m, idx, val);
    }
    else{
        if(tree[node].r == -1) {tree[node].r = pv++; tree.emplace_back();}
        update(tree[node].r, m+1, e, idx, val);
    }
    int a = tree[node].l != -1 ? tree[tree[node].l].mx : -1e9;
    int b = tree[node].r != -1 ? tree[tree[node].r].mx : -1e9;
    tree[node].mx = max(a, b);
}

int query(int node, ll s, ll e, int l, int r)
{
    if(node == -1) return -1e9;
    if(l > e || r < s) return -1e9;
    if(l <= s && e <= r) return tree[node].mx;
    ll m = s + e >> 1;
    return max(query(tree[node].l, s, m, l, r), query(tree[node].r, m+1, e, l, r));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> X;
    for(int i=1; i<=N; i++) cin >> arr[i];
    ll s = 0, e = *max_element(arr + 1, arr + N + 1) - *min_element(arr + 1, arr + N + 1);
   while(s <= e){
        ll m = s + e >> 1;
        memset(dp, 0, sizeof(dp));
        tree.clear();
        tree.emplace_back();
        pv = 1;
        dp[1] = 1;
        bool flag = false;
        for(int i=2; i<=N; i++){
            update(0, 0, 1e9, arr[i-1], dp[i-1]);
            dp[i] = query(0, 0, 1e9, arr[i] - m, arr[i] + m) + 1;
            if(dp[i] <= 0) dp[i] = 1;
            if(dp[i] >= X){
                flag = true;
                break;
            }
        }
        if(flag) e = m - 1;
        else s = m + 1;
    }
    if(N == 1) cout << 0 << '\n';
    else cout << s << '\n';

    return 0;
}