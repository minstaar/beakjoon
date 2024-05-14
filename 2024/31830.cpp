#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
    char l, r;
    int v;
};

Node init(string& str, vector<Node>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = {str[start], str[start], 1};
    int mid = start + end >> 1;
    Node a = init(str, tree, node * 2, start, mid);
    Node b = init(str, tree, node * 2 + 1, mid + 1, end);
    tree[node].l = a.l;
    tree[node].r = b.r;
    tree[node].v = a.v + b.v - (a.r == b.l);
    return tree[node];
}

void update_lazy(vector<Node>& tree, vector<int>& lazy, int node, int start, int end)
{
    if(!lazy[node]) return;
    tree[node].l = (tree[node].l - 'A' + lazy[node]) % 26 + 'A';
    tree[node].r = (tree[node].r - 'A' + lazy[node]) % 26 + 'A';
    if(start != end){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(vector<Node>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int val)
{
    update_lazy(tree, lazy, node, start, end);
    if(left > end || right < start) return;
    if(left <= start && end <= right){
        lazy[node] += val;
        update_lazy(tree, lazy, node, start, end);
        return;
    }
    int mid = start + end >> 1;
    update(tree, lazy, node * 2, start, mid, left, right, val);
    update(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);
    tree[node].l = tree[node*2].l;
    tree[node].r = tree[node*2+1].r;
    tree[node].v = tree[node*2].v + tree[node*2+1].v - (tree[node*2].r == tree[node*2+1].l);
}

Node query(vector<Node>& tree, vector<int>& lazy, int node, int start, int end, int left, int right)
{
    update_lazy(tree, lazy, node, start, end);
    if(left > end || right < start) return {'0', '0', 0};
    if(left <= start && end <= right) return tree[node];
    int mid = start + end >> 1;
    Node a = query(tree, lazy, node * 2, start, mid, left, right);
    Node b = query(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
    if(a.r == '0' && b.l == '0'){
        return {a.l, b.r, a.v + b.v};
    }
    else return {a.l, b.r, a.v + b.v - (a.r == b.l)};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;
    string str; cin >> str;
    vector<Node> tree(N*4);
    vector<int> lazy(N*4);
    init(str, tree, 1, 0, N -1);
    while(Q--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            cout << query(tree, lazy, 1, 0, N - 1, b - 1, c - 1).v << '\n';
        }
        if(a == 2){
            update(tree, lazy, 1, 0, N - 1, b - 1, c - 1, 1);
        }
    }

    return 0;
}