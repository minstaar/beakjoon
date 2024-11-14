#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; ll K; cin >> N >> K;
    vector<ll> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    ll crit = -1e18;
    int idx = 0;
    for(int i=1; i<N; i++){
        if(arr[i] > arr[0] + K * i && arr[i] - (arr[0] + K * i) > crit){
            crit = arr[i] - (arr[0] + K * i);
            idx = i;
        }
    }

    ll cnt = 0;
    ll a = arr[idx] - K * idx;
    for(int i=0; i<N; i++){
        cnt += a - arr[i];
        a += K;
    }
    cout << cnt << '\n';

    return 0;
}