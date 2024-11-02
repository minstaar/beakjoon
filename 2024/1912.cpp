#include <iostream>
#include <algorithm>
using namespace std;

int N, psum[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        psum[i] += psum[i-1] + a;
    }

    int mn = min(0, psum[1]), ans = psum[1];
    for(int i=2; i<=N; i++){
        ans = max(ans, psum[i] - mn);
        mn = min(mn, psum[i]);
    }
    cout << ans << '\n';

    return 0;
}