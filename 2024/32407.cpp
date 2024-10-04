#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N, arr[17];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr[__builtin_ctz(a)]++;
    }

    ll cnt = 0;
    for(int i=0; i<16; i++){
        cnt += arr[i];
        cnt <<= 1LL;
    }
    cnt += arr[16];
    ll ans = cnt / 65536 + (cnt % 65536 ? 1 : 0);
    cout << ans << '\n';
    
    return 0;
}