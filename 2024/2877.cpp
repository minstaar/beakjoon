#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int mod = 2, k = 1;
    while(k + mod <= N){
        k += mod;
        mod <<= 1;
    }
    mod >>= 1;

    while(N > 0){
        if(N - k < mod) cout << 4;
        else cout << 7;
        N = k - mod + (N - k) % mod;
        k -= mod;
        mod >>= 1;
    }

    return 0;
}