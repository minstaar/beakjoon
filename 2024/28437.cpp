#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, arr[100010], dp[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    
    for(int i=1; i<=MAX; i++){
        for(int j=i*2; j<=MAX; j+=i){
            dp[j] += dp[i];
        }
    }
    
    int Q; cin >> Q;
    while(Q--){
        int a; cin >> a;
        cout << dp[a] << ' ';
    }
    cout << '\n';

    return 0;
}