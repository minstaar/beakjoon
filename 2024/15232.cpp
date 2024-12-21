#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int R, C; cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}