#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, sq, arr[100010];
vector<int> bucket[330];

void update(int idx, int val)
{
    int id = idx / sq;
    for(int i=0; i<bucket[id].size(); i++){
        if(bucket[id][i] == arr[idx]){
            bucket[id].erase(bucket[id].begin() + i);
            break;
        }
    }
    for(int i=0; i<=bucket[id].size(); i++){
        if(bucket[id][i] >= val || i == bucket[id].size()){
            bucket[id].insert(bucket[id].begin() + i, val);
            break;
        }
    }
    arr[idx] = val;
}

int query(int l, int r, int k)
{
    int cnt = 0;
    while(l % sq != 0 && l <= r) cnt += (arr[l++] > k);
    while((r + 1) % sq != 0 && l <= r) cnt += (arr[r--] > k);
    while(l <= r){
        cnt += bucket[l/sq].end() - upper_bound(bucket[l/sq].begin(), bucket[l/sq].end(), k);
        l += sq;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    sq = sqrt(N);
    for(int i=1; i<=N; i++){
        bucket[i/sq].push_back(arr[i]);
        if((i + 1) % sq == 0) sort(bucket[i/sq].begin(), bucket[i/sq].end());
    }

    int Q; cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 2){
            int i, v; cin >> i >> v;
            update(i, v);
        }
        else{
            int i, j, k; cin >> i >> j >> k;
            cout << query(i, j, k) << '\n';
        }
    }

    return 0;
}