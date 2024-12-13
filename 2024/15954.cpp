#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
using ld = long double;
using ll = long long;

ll N, K, arr[510];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    auto var = [&](int s, int e, ld m){
        ld ret = 0;
        for(int i=s; i<=e; i++){
            ret += (arr[i] - m) * (arr[i] - m);
        }
        return ret / (e - s + 1);
    };

    ld ans = 1e18;
    for(int i=K; i<=N; i++){
        ld m = 0;
        for(int j=0; j<i; j++) m += arr[j];
        ans = min(ans, var(0, i - 1, m / i));

        for(int j=0; j<N-i; j++){
            m += arr[j+i] - arr[j];
            ans = min(ans, var(j + 1, j + i, m / i));
        }
    }
    cout << fixed << setprecision(11) << sqrt(ans) << '\n';

    return 0;
}