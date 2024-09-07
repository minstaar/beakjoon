#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    ll sum = N * (N + 1) / 2;
    cout << sum << '\n' << sum * sum << '\n' << sum * sum << '\n';

    return 0;
}