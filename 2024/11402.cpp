#include <iostream>
using namespace std;
using ll = long long;

int pw(int a, int n, int p)
{
    int ret = 1;
    while(n){
        if(n & 1) ret = ret * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ret;
}

int nCk(int N, int K, int M)
{
    int a = 1, b = 1;
    for(int i=N; i>=N-K+1; i--) a = a * i % M;
    for(int i=K; i>=1; i--) b = b * i % M;
    return a * pw(b, M - 2, M) % M;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, K, M; cin >> N >> K >> M;

    int res = 1;
    while(N || K){
        res = res * nCk(N % M, K % M, M) % M;
        N /= M, K /= M;
    }
    cout << res << '\n';

    return  0;
}
