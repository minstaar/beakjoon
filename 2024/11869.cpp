#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    ll grundy = 0;
    for(int i=0; i<N; i++){
        ll t; cin >> t;
        grundy ^= t;
    }
    cout << (grundy ? "koosaga" : "cubelover") << '\n';

    return 0;
}