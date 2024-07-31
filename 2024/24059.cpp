#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll pw(ll n, ll p, ll m)
{
    ll ret = 1;
    while(p){
        if(p & 1) ret = ret * n % m;
        n = n * n % m;
        p >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> arr(N + 1);
    for(int i=0; i<=N; i++) cin >> arr[i];
    int M; cin >> M;

    ll res;
    if(N == 0) res = arr[0] % M;
    else if(N == 1){
        res = pw(arr[1], arr[0], M);
    }
    else{
        res = pw(arr[1], arr[0], M - 1);
        res += M - 1;
        res = pw(arr[2], res, M);
    }
    cout << res << '\n';

    return 0;
}