#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 30010;

struct Node
{
    int x;
    int y1, y2;
    bool state;
    bool operator < (const Node& other)const{
        return x < other.x;
    }
};

void update(vector<int>& tree, vector<int>& cnt, int node, int start, int end, int left, int right, int val)
{
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        cnt[node] += val;
    }
    else{
        int mid = start + end >> 1;
        update(tree, cnt, node * 2, start, mid, left, right, val);
        update(tree, cnt, node * 2 + 1, mid + 1, end, left, right, val);
    }
    if(cnt[node] > 0) tree[node] = end - start + 1;
    else tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Node> arr;
    vector<int> tree(MAX*4), cnt(MAX*4);
    for(int i=0; i<N; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        arr.push_back({a, b, d - 1, true});
        arr.push_back({c, b, d - 1, false});
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    update(tree, cnt, 1, 0, MAX, arr[0].y1, arr[0].y2, 1);
    for(int i=1; i<arr.size(); i++){
        int diff = arr[i].x - arr[i-1].x;
        ans += tree[1] * diff;
        if(arr[i].state){
            update(tree, cnt, 1, 0, MAX, arr[i].y1, arr[i].y2, 1);
        }
        else{
            update(tree, cnt, 1, 0, MAX, arr[i].y1, arr[i].y2, -1);
        }
    }
    cout << ans << '\n';

    return 0;
}