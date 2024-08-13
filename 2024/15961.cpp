#include <iostream>
#include <algorithm>
using namespace std;

int N, D, K, C, arr[3003010], sub[3010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> D >> K >> C;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<K-1; i++) arr[i+N] = arr[i];

    int cnt = 0, ans;
    for(int i=0; i<K; i++){
        if(++sub[arr[i]] == 1) cnt++;
    }
    if(++sub[C] == 1) cnt++;
    ans = cnt;
    for(int i=0; i<N-1; i++){
        if(--sub[arr[i]] == 0) cnt--;
        if(++sub[arr[i+K]] == 1) cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}