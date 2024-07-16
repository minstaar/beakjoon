#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    int ans = 0;
    for(int i=1; i<=N; i++){
        int x = i, mx = 1;
        for(int j=2; j<=x; j++){
            while(x % j == 0){
                mx = max(mx, j);
                x /= j;
            }
        }
        if(mx <= K) ans++;
    }
    cout << ans << '\n';

    return 0;
}