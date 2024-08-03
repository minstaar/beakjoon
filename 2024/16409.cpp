#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX = 1e7 + 10;
int mu[MAX], psum[MAX];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    mu[1] = 1;
    for(int i=1; i<=MAX; i++){
        for(int j=i*2; j<=MAX; j+=i) mu[j] -= mu[i];
    }
    for(int i=1; i<=MAX; i++) psum[i] = psum[i-1] + mu[i];

    auto solve = [&](int n, int m){
        ll ans = 0;
        int j;
        for(int i=1; i<=min(n, m); i=j+1){
            j = min(n / (n / i), m / (m / i));
            ans += 1LL * (psum[j] - psum[i-1]) * (n / i) * (m / i);
        }
        return ans;
    };

    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << solve(b, d) - solve(b, c - 1) - solve(a - 1, d) + solve(a - 1, c - 1) << '\n';

    return 0;
}