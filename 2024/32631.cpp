#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N, K;
vector<ll> psumA(5010), psumB(5010);
vector<ll> resA(5010, 1e18), resB(5010, 1e18);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        psumA[i] = psumA[i-1] + a;
    }
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        psumB[i] = psumB[i-1] + a;
    }

    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            resA[N-i] = min(resA[N-i], psumA[j] - psumA[j-i]);
        }
        for(int j=i; j<=N; j++){
            resB[N-i] = min(resB[N-i], psumB[j] - psumB[j-i]);
        }
    }
    resA[N] = resB[N] = 0;

    ll res = 1e18;
    for(int i=0; i<=K; i++){
        res = min(res, max(resA[i], resB[K-i]));
    }
    cout << res << '\n';

    return 0;
}