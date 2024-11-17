#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll A, B, K, M; cin >> A >> B >> K >> M;

    int s = pow(10, K-1), e = pow(10, K);
    ll res = 0;
    for(int i=s; i<e; i++){
        int x = i;
        for(int l=0; l<K; l++){
            ll j = x;
            int cnt = K - l;
            while(j <= B){
                if(A <= j && cnt >= K){
                    res += (j % M == 0);
                }
                j += 1LL * i * pow(10, cnt);
                cnt += K;
            }
            x /= 10;
        }
    }
    cout << res << '\n';

    return 0;
}