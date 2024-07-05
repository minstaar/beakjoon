#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int x = 0;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        x ^= t;
    }
    cout << (x ? "koosaga" : "cubelover") << '\n';

    return 0;
}