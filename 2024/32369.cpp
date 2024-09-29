#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, A, B; cin >> N >> A >> B;
    int x = 1, y = 1;
    for(int i=0; i<N; i++){
        x += A, y += B;
        if(x < y) swap(x, y);
        else if(x == y) y--;
    }
    cout << x << ' ' << y << '\n';

    return 0;
}