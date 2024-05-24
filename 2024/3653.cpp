#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 200010;

void init(vector<int>& tree, int node, int start, int end, int range)
{
    if(start == end){
        if(start <= range) tree[node] = 1;
        else tree[node] = 0;
    }
    else{
        int mid = start + end >> 1;
        init(tree, node * 2, start, mid, range);
        init(tree, node * 2 + 1, mid + 1, end, range);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(vector<int>& tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    tree[node] += val;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, index, val);
        update(tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

int query(vector<int>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    int pos[MAX], idx;
    vector<int> tree(MAX*4);
    while(T--){
        int N, M; cin >> N >> M;
        init(tree, 1, 0, MAX, N - 1);
        for(int i=N; i>=1; i--){
            pos[i] = N - i;
        }
        idx = N;
        for(int i=1; i<=M; i++){
            int a; cin >> a;
            cout << query(tree, 1, 0, MAX, pos[a] + 1, MAX) << ' ';
            update(tree, 1, 0, MAX, pos[a], -1);
            pos[a] = idx;
            update(tree, 1, 0, MAX, idx, 1);
            idx++;
        }
        cout << '\n';
    }

    return 0;
}