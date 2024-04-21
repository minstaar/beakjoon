#include <iostream>
using namespace std;

int N, K, arr[50010];
long long psum[50010], dp[50010];
long long numberOfInterval[50010], queue[50010], candidates[50010];

long long func(long long i, long long j)
{
    return dp[i] + (psum[j] - psum[i]) * (j - i);
}

long long cross(long long i, long long j)
{
    long long l = j + 1, r = N + 1;
    while(l < r){
        long long m = l + r >> 1;
        if(func(i, m) <= func(j, m)) l = m + 1;
        else r = m;
    }
    return l - 1;
}

void monotoneQueueOpt(long long lamda)
{
    long long front = 0, rear = 1;
    queue[0] = 0, candidates[0] = N;
    for(int i=1; i<=N; i++){
        while(candidates[front] < i) front++;
        dp[i] = func(queue[front], i) + lamda;
        numberOfInterval[i] = numberOfInterval[queue[front]] + 1;
        while(front + 1 < rear && candidates[rear-2] >= cross(queue[rear-1], i)) rear--;
        candidates[rear-1] = cross(queue[rear-1], i);
        queue[rear] = i;
        candidates[rear++] = N;
    }
}

long long binarySearch(long long l, long long r)
{
    if(l >= r) return l;
    long long m = l + r >> 1;
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

    long long lamda = binarySearch(0, 1e14);
    monotoneQueueOpt(lamda);

    cout << dp[N] - lamda * K << '\n';

    return 0;
}
