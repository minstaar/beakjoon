#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    K -= N - 1;
    cout << K / N <<'\n';

    return 0;
}