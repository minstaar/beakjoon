#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<pii> arr(K);
    vector<int> res(N);
    for(int i=0; i<K; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end(), greater<>());

    int idx = 0, pv = 0;
    while(idx < N){
        res[idx] = arr[pv].second;
        if(--arr[pv].first == 0) pv++;
        idx += 2;
    }
    idx = 1;
    while(idx < N){
        res[idx] = arr[pv].second;
        if(--arr[pv].first == 0) pv++;
        idx += 2;
    }

    bool flag = true;
    for(int i=1; i<N; i++){
        if(res[i] == res[i-1]){
            flag = false;
            break;
        }
    }
    if(flag){
        for(int i=0; i<N; i++) cout << res[i] << ' ';
    }
    else{
        cout << "-1\n";
    }

    return 0;
}