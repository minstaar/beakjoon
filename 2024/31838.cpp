#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 500000;
ll arr[MAX*3+10], psum[MAX*3+10], dp[MAX*3+10];
ll query[MAX*3+10]; //Max value of dp[i] - psum[i]

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K; cin >> N >> K;
    for(int i=K+1; i<=K+N+1; i++) cin >> arr[i];
    for(int i=1; i<=N+2*K; i++){
        psum[i] = psum[i-1] + arr[i];
    }

    for(int i=1; i<=N+2*K; i++){
        if(i >= K)dp[i] = max(dp[i-1], query[i-K] + psum[i]);
        query[i] = max(query[i-1], dp[i] - psum[i]);
    }
    cout << dp[N+2*K] << '\n';

    return 0;
}