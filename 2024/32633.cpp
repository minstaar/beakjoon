#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; ll L; cin >> N >> L;
    vector<ll> A(N); for(int i=0; i<N; i++) cin >> A[i];
    vector<int> B(N); for(int i=0; i<N; i++) cin >> B[i];
    ll res = 1;
    for(int i=0; i<N; i++){
        if(B[i]) res = res * A[i] / __gcd(res, A[i]);
        if(res > L){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i=0; i<N; i++){
        if(!B[i] && res % A[i] == 0){
            cout << "-1\n";
            return 0;
        }
    }
    cout << res << '\n';

    return 0;
}