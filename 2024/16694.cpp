#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int x = 0;
    bool flag = 0;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        x ^= t;
        flag |= x > 1;
    }
    if(flag) cout << (!x ? "cubelover" : "koosaga") << '\n';
    else cout << (x ? "cubelover" : "koosaga") << '\n';

    return 0;
}