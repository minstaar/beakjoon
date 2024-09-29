#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
vector<int> A, B;
ll fac[200010], inv_fac[200010];

ll pow(ll a, ll n, ll m)
{
    ll ret = 1;
    while(n){
        if(n & 1) ret = ret * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ret;
}

ll comb(int n, int r)
{
    if(r == 0 || n == r) return 1;
    return fac[n] * inv_fac[n-r] % MOD * inv_fac[r] % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fac[0] = 1;
    for(int i=1; i<=200000; i++){
        fac[i] = fac[i-1] * i % MOD;
    }

    inv_fac[200000] = pow(fac[200000], MOD - 2, MOD);
    for(int i=200000; i>0; i--){
        inv_fac[i-1] = inv_fac[i] * i % MOD;
    }

    int N, M; cin >> N >> M;
    A.resize(N);
    B.resize(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int mn = 2e9, idx = M - 1;
    for(int i=0; i<N; i++){
        if(idx >= 0){
            mn = min(mn, A[i] + B[idx]);
            idx--;
        }
        else mn = min(mn, A[i]);
    }

    ll res1 = 1;
    int cnt = 0;
    for(int i=0; i<N && A[i]<mn; i++){
        res1 *= (B.end() - lower_bound(B.begin(), B.end(), mn - A[i]) - i) % MOD;
        res1 %= MOD;
        cnt++;
    }

    ll res2 = 0;
    int leftA = N - cnt, leftB = M - cnt;
    for(int i=0; i<=min(leftA, leftB); i++){
        ll tmp = comb(leftA, i) * comb(leftB, i) % MOD * fac[i] % MOD;
        res2 = (res2 + tmp) % MOD;
    }

    cout << res1 * res2 % MOD << '\n';

    return 0;
}