#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Data
{
    int s, e, k;
    bool operator < (const Data &o) const{
        return e < o.e;
    }
}arr[100010];

int N, dp[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].s >> arr[i].e >> arr[i].k;
    }

    sort(arr, arr + N);
    dp[0] = arr[0].k;
    for(int i=1; i<N; i++){
        int t = lower_bound(arr, arr + i, arr[i], [](const Data &A, const Data &B){
            return A.e < B.s;
        }) - arr - 1;
        dp[i] = max(dp[i-1], dp[t] + arr[i].k);
    }

    cout << dp[N-1] << '\n';

    return 0;
}