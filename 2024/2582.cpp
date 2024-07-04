#include <bits/stdc++.h>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 mt(rd());
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int arr[40] = {};
    uniform_int_distribution<int> ran(0, n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin >> c;
            arr[i] <<= 1;
            if(c == 'H') arr[i] |= 1;
        }
    }

    int ans = n * n;
    int a = 0, b = 0;
    int prev = n * n;
    double t = 1.0, k = 2.5;
    for(int i=0; i<10101; i++){
        b = a ^ (1 << ran(mt));
        int now = 0;
        for(int j=0; j<n; j++){
            int h = __builtin_popcount(arr[j] ^ b);
            now += min(h, n - h);
        }
        double p = exp((prev - now) / (k * t));
        if(p > (double)ran(mt) / (n - 1)){
            a = b;
            prev = now;
        }
        ans = min(ans, prev);
        t *= 0.9999;
    }

    cout << ans << '\n';

    return 0;
}