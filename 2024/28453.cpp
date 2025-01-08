#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(a >= 300) cout << "1 ";
        else if(a >= 275) cout << "2 ";
        else if(a >= 250) cout << "3 ";
        else cout << "4 ";
    }

    return 0;
}