#include <iostream>
#include <deque>
using namespace std;
using ll = long long;

int N, K, arr[100010];
ll psum[100010], dp[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        psum[i] += psum[i-1] + arr[i];
    }

    deque<int> deq;
    for(int i=1; i<=K; i++){
        dp[i] = psum[i];
        while(!deq.empty() && dp[deq.back()-1] - psum[deq.back()] < dp[i-1] - psum[i]) deq.pop_back();
        deq.push_back(i);
    }

    for(int i=K+1; i<=N; i++){
        while(deq.size() > 1 && deq.front() < i - K) deq.pop_front();
        while(!deq.empty() && dp[deq.back()-1] - psum[deq.back()] < dp[i-1] - psum[i]) deq.pop_back();
        deq.push_back(i);
        dp[i] = psum[i] - psum[deq.front()] + dp[deq.front() - 1];
    }

    cout << dp[N] << '\n';

    return 0;   
}