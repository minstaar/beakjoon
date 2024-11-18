#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, S, E; cin >> N >> S >> E;
    double res = 0;
    for(int i=0; i<N; i++){
        ll r, a, d; cin >> r >> a >> d;
        ll p = E / (r + a);
        ll q = E % (r + a);
        res += p * d;
        if(q > r) res += (double)(q - r) / a * d;

        p = S / (r + a);
        q = S % (r + a);
        res -= p * d;
        if(q > r) res -= (double)(q - r) / a * d;
    }

    cout << fixed << setprecision(6) << res / (E - S) << '\n';

    return 0;
}