#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
struct Data
{
    int x, y, z;
    bool operator<(const Data& other)const{
        return x < other.x;
    }
};

void update(vector<int>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    update(tree, node * 2, start, mid, index, val);
    update(tree, node * 2 + 1, mid + 1, end, index, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int query(vector<int>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return INF;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return min(query(tree, node * 2, start, mid, left, right), query(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> tree(N*4, INF);
    vector<Data> arr(N);
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr[a-1].x = i;
    }
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr[a-1].y = i;
    }for(int i=0; i<N; i++){
        int a; cin >> a;
        arr[a-1].z = i;
    }
    sort(arr.begin(), arr.end());

    int ans = 1;
    update(tree, 1, 0, N - 1, arr[0].y, arr[0].z);
    for(int i=1; i<N; i++){
        if(arr[i].z < query(tree, 1, 0, N - 1, 0, arr[i].y - 1)){
            ans++;
        }
        update(tree, 1, 0, N - 1, arr[i].y, arr[i].z);
    }
    cout << ans << '\n';

    return 0;
}