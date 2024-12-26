#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    int sum = 0;
    while(N > 0){
        sum += N;
        N /= M;
    }
    cout << sum << '\n';

    return 0;
}