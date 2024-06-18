#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M, X;
ll cost[100010], budget[100010];

bool check(int k)
{
    ll sum = 0;
    for(int i=0; i<k; i++){
        ll diff = budget[k-i-1] - cost[i];
        if(diff < 0) sum -= diff;
    }
    return sum <= X;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> X;
    for(int i=0; i<N; i++) cin >> cost[i];
    for(int i=0; i<M; i++) cin >> budget[i];
    sort(cost, cost + N);
    sort(budget, budget + M, greater<>());

    int l = 0, r = min(N, M);
    int ans = 0;
    while(l <= r){
        int m = l + r >> 1;
        if(check(m)){
            ans = m, l = m + 1;
        }
        else r = m - 1;
    }
    cout << ans << '\n';

    return 0;
}