#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;

void update(vector<int>& tree, int node, int start, int end, int val, int diff)
{
    if(val < start || val > end) return;
    tree[node] += diff;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, val, diff);
        update(tree, node * 2 + 1, mid + 1, end, val, diff);
    }
}

int query(vector<int>& tree, int node, int start, int end, int val)
{
    tree[node] -= 1;
    if(start == end) return start;
    int mid = start + end >> 1;
    if(tree[node*2] >= val){
        return query(tree, node * 2, start, mid, val);
    }
    else{
        return query(tree, node * 2 + 1, mid + 1, end, val - tree[node*2]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> tree(MAX*4);
    for(int i=0; i<N; i++){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            cout << query(tree, 1, 0, MAX, x) << '\n';
        }
        if(q == 2){
            int val, cnt; cin >> val >> cnt;
            update(tree, 1, 0, MAX, val, cnt);
        }
    }
}