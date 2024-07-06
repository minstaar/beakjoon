#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    cout << (N % 7 == 0 || N % 7 == 2 ? "CY" : "SK") << '\n';

    return 0;
}