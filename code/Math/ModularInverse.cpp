#include <bits/stdc++.h>
using namespace std;

int modinv(int x, int n){ //mod = n
    int a = n, b = 0;
    int c = x % n, d = 1;
    while(c){
        int q = a / c;
        int e = a - q * c, f = (b - 1LL * q * d) % n;
        a = c, b = d;
        c = e, d = f;
    }
    if(a == 1) return b < 0 ? b + n : b;
    return -1;
}