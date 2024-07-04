#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int check = 0, sum = 0, tmp = 1e9;
    for(int i=0; i<N; i++){
        int x; cin >> x;
        check ^= x;
        sum += x;
        tmp = min(tmp, x);
    }
    
    if(check == 0) cout << sum - tmp << '\n';
    else cout << 0 << '\n';

    return 0;

}