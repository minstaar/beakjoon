#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;


struct Node
{
    int l = -1, r = -1, val = 0, idx;
};

struct Data
{
    int depth, val, idx;
    bool operator < (const Data &o) const{
        if(depth == o.depth){
            return val < o.val;
        }
        return depth < o.depth;
    }
};

vector<Node> tree(200010);
int idx[200010], pv;

int update(int cur, int val, int depth, int v)
{
    int it = 1;
    while(it <= depth){
        if(tree[cur].val > val){
            if(tree[cur].l == -1){
                tree[cur].l = ++pv;
                tree[pv] = {-1, -1, val, v};
                idx[v] = pv;
                return it + 1;
            }
            else cur = tree[cur].l;
        }
        else{
            if(tree[cur].r == -1){
                tree[cur].r = ++pv;
                tree[pv] = {-1, -1, val, v};
                idx[v] = pv;
                return it + 1;
            }
            else cur = tree[cur].r;
        }
        it++;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<Data> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].val >> arr[i].depth;
        arr[i].idx = i;
    }
    sort(arr.begin(), arr.end());
    bool flag = true;
    if(arr[0].depth == 1){
        tree[0] = {-1, -1, arr[0].val};
        idx[arr[0].idx] = 0;
    }
    else{
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1; i<N; i++){
        if(arr[i].depth != update(0, arr[i].val, arr[i].depth, arr[i].idx)){
            flag = false;
            break;
        }
    }
    if(flag){
        for(int i=0; i<N; i++){
            int lc, rc;
            if(tree[idx[i]].l == -1) lc = -1;
            else lc = tree[tree[idx[i]].l].idx + 1;
            if(tree[idx[i]].r == -1) rc = -1;
            else rc = tree[tree[idx[i]].r].idx + 1;
            cout << lc << ' ' << rc << '\n';
        }
    }
    else cout << -1 << '\n';

    return 0;
}