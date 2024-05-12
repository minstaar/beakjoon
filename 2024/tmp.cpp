#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> diff(200010), loc_tree(200010*4);

int loc_init(vector<int>& diff, vector<int>& loc_tree, int node, int start, int end)
{
    if(start == end) return loc_tree[node] = diff[start];

    int mid = start + end >> 1;
    return loc_tree[node] = loc_init(diff, loc_tree, node * 2, start, mid) + loc_init(diff, loc_tree, node * 2 + 1, mid + 1, end);
}

int loc_query(vector<int>& loc_tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return loc_tree[node];

    int mid = start + end >> 1;
    int a = loc_query(loc_tree, node * 2, start, mid, left, right);
    int b = loc_query(loc_tree, node * 2 + 1, mid + 1, end, left, right);
    return a + b;
}

void loc_update(vector<int>& loc_tree, int node, int start, int end, int index, int val)
{
    if(index < start || index > end) return;
    loc_tree[node] += val;
    if(start != end){
        int mid = start + end >> 1;
        loc_update(loc_tree, node * 2, start, mid, index, val);
        loc_update(loc_tree, node * 2 + 1, mid + 1, end, index, val);
    }
}

int init(string& str, vector<int>& tree, int node, int start, int end)
{
    if(start == end) return tree[node] = 1;
    
    int mid = start + end >> 1;
    int a = init(str, tree, node * 2, start, mid);
    int b = init(str, tree, node * 2 + 1, mid + 1, end);
    tree[node] = a + b;
    int q1 = loc_query(loc_tree, 1, 0, N-1, 0, mid);
    int q2 = loc_query(loc_tree, 1, 0, N-1, 0, mid + 1);
    if(q1 == q2) tree[node]--;
    return tree[node];
}

int query(string& str, vector<int>& tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    
    int mid = start + end >> 1;
    int a = query(str, tree, node * 2, start, mid, left, right);
    int b = query(str, tree, node * 2 + 1, mid + 1, end, left, right);
    if(a == 0 || b == 0) return a + b;
    int q1 = loc_query(loc_tree, 1, 0, N-1, 0, mid);
    int q2 = loc_query(loc_tree, 1, 0, N-1, 0, mid + 1);
    if(q1 == q2) return a + b - 1;
    else return a + b;
}

int propagate(vector<int>& tree, int node, int start, int end, int index)
{
    if(index < start || index > end) return tree[node];

    if(start != end){
        int mid = start + end >> 1;
        int a = propagate(tree, node * 2, start, mid, index);
        int b = propagate(tree, node * 2 + 1, mid + 1, end, index);
        tree[node] = a + b;
        int q1 = loc_query(loc_tree, 1, 0, N-1, 0, mid);
        int q2 = loc_query(loc_tree, 1, 0, N-1, 0, mid + 1);
        if(q1 == q2) tree[node]--;
    }
    return tree[node];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int Q; cin >> N >> Q;
    string str; cin >> str;
    vector<int> tree(N*4);
    diff[0] = str[0] - 'A';
    for(int i=1; i<N; i++){
        diff[i] = str[i] - str[i-1];
    }
    loc_init(diff, loc_tree, 1, 0, N-1);
    init(str, tree, 1, 0, N - 1);
    
    for(int i=0; i<Q; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            cout << query(str, tree, 1, 0, N - 1, b - 1, c - 1) << '\n';
        }
        if(a == 2){
            loc_update(loc_tree, 1, 0, N - 1, b - 1, 1);
            loc_update(loc_tree, 1, 0, N - 1, c, -1);
            if(b - 2 >= 0) propagate(tree, 1, 0, N - 1, b - 2);
            if(c <= N - 1) propagate(tree, 1, 0, N - 1, c);
        }
    }

    return 0;
}