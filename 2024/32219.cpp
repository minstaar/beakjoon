#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int r, c; cin >> r >> c;
        if(r != c){
            cout << "jinseo\n";
            if(r < c) cout << r << ' ' << r << '\n';
            else cout << c << ' ' << c << '\n';
        }
        else cout << "dohoon\n";
    }

    return 0; 
}