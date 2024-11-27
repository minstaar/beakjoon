#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N, K; cin >> N >> K;
    vector<int> arr(N), diff(N-1);
    ll sum = 0;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N-1; i++){
        diff[i] = arr[i+1] - arr[i];
        sum += diff[i];
    }
    sort(diff.begin(), diff.end(), greater<>());
    for(int i=0; i<K-1; i++) sum -= diff[i];
    cout << sum << '\n';

    return 0;
}