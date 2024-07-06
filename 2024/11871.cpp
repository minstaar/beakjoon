#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int x = 0;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        x ^= (t % 2 ? t / 2 + 1 : t / 2 - 1);
    }
    cout << (x ? "koosaga" : "cubelover") << '\n';

    return 0;
}