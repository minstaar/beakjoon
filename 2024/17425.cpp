#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 1000000;
ll F[1000010], G[1000010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fill(F, F + MAX + 1, 1);
    for(int i=2; i<=MAX; i++){
        for(int j=i; j<=MAX; j+=i){
            F[j] += i;
        }
    }
    for(int i=1; i<=MAX; i++) G[i] = G[i-1] + F[i];

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        cout << G[n] << '\n';
    }

    return 0;
}