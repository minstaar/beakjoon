#include <iostream>
#include <algorithm>
using namespace std;

struct Data
{
    int sz, idx;
    bool operator < (const Data &o) const{
        return sz > o.sz;
    }
};

int N, Q;
vector<int> A(250010), B(250010), diff(250010), ans(250010);
vector<Data> arr(250010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    for(int i=0; i<N; i++) diff[i] = A[i] - B[i];
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> arr[i].sz;
        arr[i].idx = i;
    }

    sort(arr.begin(), arr.end());
    int idx = 0;
    for(int i=0; i<=N; i++){
        while(arr[idx].sz > diff[i]){
            ans[arr[idx].idx] = i;
            idx++;
        }
    }

    for(int i=0; i<Q; i++) cout << ans[i] << '\n';

    return 0;
}