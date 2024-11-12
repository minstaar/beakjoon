#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int K, N; cin >> K >> N;
    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(i == K) continue;
        if(__gcd(i, K) <= 2) cnt++;
    }
    
    cout << cnt << '\n';

    return 0;
}