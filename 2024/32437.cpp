#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int a = 1, b = 2;
    if(N == 1) cout << a << '\n';
    else if(N == 2) cout << b << '\n';
    else{
        for(int i=3; i<=N; i++){
            int tmp = b;
            b += a;
            a = tmp;
        }
        cout << b << '\n';
    }

    return 0;
}