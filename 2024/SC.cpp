#include <iostream>
using namespace std;

bool cnt[2010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int l, r, x; cin >> l >> r >> x;
    for(int i=l; i<=r; i++){
        cnt[i|x] = true;
    }
    for(int i=0; i<=2000; i++){
        if(!cnt[i]) {cout << i << '\n'; break;}
    }

    return 0;
}