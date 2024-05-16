#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 400010;
vector<int> compressY;
struct Node
{
    int x;
    int y1, y2;
    bool is_start;
    bool operator < (const Node& other)const{
        return x < other.x;
    }
};

void update(vector<ll>& tree, vector<ll>& cnt, int node, int start, int end, int left, int right, int val)
{
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        cnt[node] += val;
    }
    else{
        int mid = start + end >> 1;
        update(tree, cnt, node * 2, start, mid , left, right, val);
        update(tree, cnt, node * 2 + 1, mid + 1, end, left, right, val);
    }
    if(cnt[node]){
        tree[node] = compressY[end] - compressY[start-1];
    }
    else{
        if(start == end) tree[node] = 0;
        else tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Node> arr;
    for(int i=0; i<N; i++){
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        arr.push_back({x1, y1, y2, true});
        arr.push_back({x2, y1, y2, false});
        compressY.push_back(y1);
        compressY.push_back(y2);
    }
    sort(arr.begin(), arr.end());
    sort(compressY.begin(), compressY.end());
    compressY.erase(unique(compressY.begin(), compressY.end()), compressY.end());

    vector<ll> tree(MAX*4), cnt(MAX*4);
    ll ans = 0;
    for(int i=0; i<arr.size(); i++){
        if(i > 0){
            int diff = arr[i].x - arr[i-1].x;
            ans += tree[1] * diff;
        }
        int y1 = lower_bound(compressY.begin(), compressY.end(), arr[i].y1) - compressY.begin();
        int y2 = lower_bound(compressY.begin(), compressY.end(), arr[i].y2) - compressY.begin();
        if(arr[i].is_start) update(tree, cnt, 1, 0, MAX, y1 + 1, y2, 1);
        else update(tree, cnt, 1, 0, MAX, y1 + 1, y2, -1);
    }
    cout << ans << '\n';

    return 0;
}