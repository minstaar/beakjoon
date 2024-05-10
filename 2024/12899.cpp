#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000001;

void update(vector<int>& tree, int node, int start, int end, int x)
{
    if(x < start || x > end) return;
    tree[node] += 1;
    if(start != end){
        int mid = start + end >> 1;
        update(tree, node * 2, start, mid, x);
        update(tree, node * 2 + 1, mid + 1, end, x);
    }
}

int query(vector<int>& tree, int node, int start, int end, int x)
{
    tree[node] -= 1;
    if(start == end) return start;
    int mid = start + end >> 1;
    if(tree[node*2] >= x){
        return query(tree, node * 2, start, mid, x);
    }
    else{
        return query(tree, node * 2 + 1, mid + 1, end, x - tree[node*2]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> tree(MAX*4);
    for(int i=0; i<N; i++){
        int q, x; cin >> q >> x;
        if(q == 1){
            update(tree, 1, 0, MAX, x);
        }
        if(q == 2){
            cout << query(tree, 1, 0, MAX, x) << '\n';
        }
    }

    return 0;
}