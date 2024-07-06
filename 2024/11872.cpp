#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int grundy = 0;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        if(x % 4 == 3) x++;
        else if(x % 4 == 0) x--;
        grundy ^= x;
    }
    cout << (grundy ? "koosaga" : "cubelover") << '\n';

    return 0;
}
