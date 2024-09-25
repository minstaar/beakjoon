#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll A, B; cin >> A >> B; A--;
    ll sum1 = 0, sum2 = 0;
    ll pw = 1;
    for(int i=0; i<=60; i++){
        sum1 += A / (pw * 2) * pw + max(A % (pw * 2) + 1 - pw, 0LL);
        sum2 += B / (pw * 2) * pw + max(B % (pw * 2) + 1 - pw, 0LL);
        pw *= 2;
    }
    cout << sum2 - sum1 << '\n';

    return 0;
}