#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    cout << (N % 7 == 1 || N % 7 == 3 ? "CY" : "SK") << '\n';

    return 0;
}