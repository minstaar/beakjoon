#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

void update(vector<ll>& tree, int node, int start, int end, int index, int diff)
{
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll Sum(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return Sum(tree, node * 2, start, mid, left, right) + Sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N);
    map<int, int> index;
    vector<ll> tree(N*4);
    ll ans = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        index[arr[i]] = i;
    }
    for(int i=0; i<N; i++){
        int j = index[i+1];
        ans += Sum(tree, 1, 0, N-1, j+1, N-1);
        update(tree, 1, 0, N-1, j, 1);
    }
    cout << ans << '\n';

    return 0;
}