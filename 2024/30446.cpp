#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N; cin >> N;
    ll tmp = N, range = 0;
    int digitN = 0;
    while(tmp > 0){
        tmp /= 10;
        digitN++;
    }
    for(int i=0; i<(digitN+1)/2; i++){
        range *= 10;
        range += 9;
    }

    ll ans = 0;
    for(int i=1; i<=range; i++){
        ll t = i, rev = 0;
        ll p1, p2;
        int digit = 0;
        while(t > 0){
            rev *= 10;
            rev += t % 10;
            t /= 10;
            digit++;
        }
        p1 = i * pow(10, digit) + rev;
        p2 = (i / 10) * pow(10, digit) + rev;
        if(p1 <= N) ans++;
        if(p2 <= N) ans ++;
    }
    cout << ans << '\n';

    return 0;
}