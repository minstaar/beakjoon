#include <iostream>
using namespace std;

const double mn = 0.99, mx = 1.01;
int N, arr[10], ans;

void solve(int cur, double val)
{
    if(cur == N){
        if(val >= mn && val <= mx) ans++;
        return;
    }
    solve(cur + 1, val);
    solve(cur + 1, val + 1.0 / arr[cur]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    solve(0, 0);
    cout << ans << '\n';

    return 0;
}