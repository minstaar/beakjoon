#include <iostream>
using namespace std;

bool cnt[1030];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l, r, x; cin >> l >> r >> x;
    for(int i=l; i<=r; i++){
        cnt[i|x] = true;
    }
    for(int i=0; i<=1024; i++){
        if(!cnt[i]) {cout << i << '\n'; break;}
    }

    return 0;
}