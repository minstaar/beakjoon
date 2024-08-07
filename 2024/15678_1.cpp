#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

int N, D, arr[100010];
ll dp[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> D;
    for(int i=0; i<N; i++) cin >> arr[i];

    deque<int> deq;
    ll res = arr[0];
    deq.push_back(0);
    dp[0] = arr[0];
    for(int i=1; i<N; i++){
        while(deq.size() > 1 && deq.front() < i - D) deq.pop_front();
        dp[i] = max(dp[deq.front()] + arr[i], (ll)arr[i]);
        res = max(res, dp[i]);
        while(!deq.empty() && dp[deq.back()] < dp[i]) deq.pop_back();
        deq.push_back(i);
    }
    cout << res << '\n';

    return 0;
}