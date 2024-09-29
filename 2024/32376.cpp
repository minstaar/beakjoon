#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    vector<double> arr(N);
    for(int i=0; i<N; i++){
        double x, y; cin >> x >> y;
        double dist = sqrt(x * x + y * y);
        arr[i] = dist;
    }
    sort(arr.begin(), arr.end());

    int mx = 0;
    for(int i=0; i<N; i++){
        int cnt = upper_bound(arr.begin(), arr.end(), arr[i] + K) - arr.begin() - i;
        mx = max(mx, cnt);
    }

    double ans = (double)100 / N * mx;
    cout << fixed;
    cout.precision(6);
    cout << ans << '\n';

    return 0;
}