#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, M; cin >> N >> M;
    ll ans = (N - 1) * M + (M - 1) * N + (N - 1) * (M - 1) * 2;
    cout << ans << '\n';

    return 0;
}