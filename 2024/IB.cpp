#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    if(ax == 0 || ay == 0){
        if(ax == 0 && bx == 0 && by < ay) cout << "3\n";
        else if(ay == 0 && by == 0 && bx < ax) cout << "3\n";
        else cout << "1\n";
    }
    else cout << "2\n";

    return 0;
}