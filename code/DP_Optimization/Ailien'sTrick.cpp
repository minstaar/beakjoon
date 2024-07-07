//#17439
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, arr[50010];
ll psum[50010], dp[50010];
ll numberOfInterval[50010], que[50010], candidates[50010];

ll func(ll i, ll j)
{
    return dp[i] + (psum[j] - psum[i]) * (j - i);
}

ll cross(ll i, ll j)
{
    ll l = j + 1, r = N + 1;
    while(l < r){
        ll m = l + r >> 1;
        if(func(i, m) <= func(j, m)) l = m + 1;
        else r = m;
    }
    return l - 1;
}

void monotoneQueueOpt(ll lamda)
{
    int front = 0, rear = 1;
    que[0] = 0, candidates[0] = N;
    for(int i=1; i<=N; i++){
        while(candidates[front] < i) front++;
        dp[i] = func(que[front], i) + lamda;
        numberOfInterval[i] = numberOfInterval[que[front]] + 1;
        while(front + 1 < rear && candidates[rear-2] >= cross(que[rear-1], i)) rear--;
        candidates[rear-1] = cross(que[rear-1], i);
        que[rear] = i;
        candidates[rear++] = N;
    }
}

ll binarySearch(ll l, ll r)
{
    if(l >= r) return l;
    ll m = l + r >> 1;
    monotoneQueueOpt(m);
    if(numberOfInterval[N] >= K) return binarySearch(m + 1, r);
    else return binarySearch(l, m);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    ll lamda = binarySearch(0, 1e14);
    monotoneQueueOpt(lamda);

    cout << dp[N] - lamda * K << '\n';

    return 0;
}
