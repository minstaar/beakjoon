#include <iostream>
using namespace std;

int modinv(int x, int n)
{
    int a = n, b = 0;
    int c = x % n, d = 1;
    while(c){
        int q = a / c;
        int e = a - q * c, f = (b - 1LL * q * d) % n;
        a = c, b = d;
        c = e, d = f;
    }
    if(a == 1) return (b + n) % n;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int k, c; cin >> k >> c;
        if(k == 1 && c == 1) cout << 2 << '\n';
        else if(k == 1) cout << 1 << '\n';
        else if(c == 1){
            if(k < 1e9) cout << k + 1 << '\n';
            else cout << "IMPOSSIBLE\n";
        }
        else{
            int res = modinv(c, k);
            if(res == -1) cout << "IMPOSSIBLE\n";
            else cout << res << '\n';
        }
    }

    return 0;
}