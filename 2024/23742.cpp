#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<ll> arr(N+1), psum(N+1);
    for(int i=1; i<=N; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.end(), greater<>());
    for(int i=1; i<=N; i++) psum[i] = psum[i-1] + arr[i];
    
    ll sum = 0;
    for(int i=1; i<=N; i++){
        sum = max(psum[i] * i, sum + arr[i]);
    }
    cout << sum << '\n';

    return 0;
}