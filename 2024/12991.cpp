#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N, K;
ll A[30010], B[30010];

bool check(ll _m)
{
    int cnt = 0;
    for(int i=0; i<N; i++){
        int s = 0, e = N-1;
        int idx = 0;
        while(s <= e){
            int m = s + e >> 1;
            if(A[i] * B[m] <= _m){
                idx = m + 1;
                s = m + 1;
            }
            else e = m - 1;
        }
        cnt += idx;
    }
    return cnt >= K;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);

    ll s = A[0] * B[0], e = A[N-1] * B[N-1];
    ll ans = 0;
    while(s <= e){
        ll m = s + e >> 1;
        if(check(m)){
            ans = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    cout << ans << '\n';

    return 0;
}