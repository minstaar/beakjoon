#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int INF = 1e9;
struct Data{
    ll sx = INF, sy = INF, ex = -INF, ey = -INF;
}arr[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int r, c, N; cin >> r >> c >> N;
    for(int i=1; i<=N; i++){
        ll idx, x, y; cin >> idx >> x >> y;
        arr[idx].sx = min(arr[idx].sx, x);
        arr[idx].sy = min(arr[idx].sy, y);
        arr[idx].ex = max(arr[idx].ex, x);
        arr[idx].ey = max(arr[idx].ey, y);
    }
    ll ans, size = -INF;
    for(int i=1; i<=N; i++){
        if(arr[i].sx == INF) continue;
        if(size < (arr[i].ex - arr[i].sx + 1) * (arr[i].ey - arr[i].sy + 1)){
            size = (arr[i].ex - arr[i].sx + 1) * (arr[i].ey - arr[i].sy + 1);
            ans = i;
        }
    }
    cout << ans << ' ' << size << '\n';

    return 0;
}