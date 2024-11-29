#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

ll solve1(vector<int> arr)
{
    sort(arr.begin(), arr.end(), greater<>());
    ll sum = 0, cnt = 0;
    for(int i=0; i<N; i++){
        if((sum + arr[i]) * (cnt + 1) < sum * cnt + arr[i]) break;
        sum += arr[i];
        cnt++;
    }

    sum *= cnt;
    for(int i=cnt; i<N; i++) sum += arr[i];

    return sum;
}

ll solve2(vector<int> arr)
{
    vector<ll> psum(N+1);
    sort(arr.begin(), arr.end(), greater<>());
    for(int i=1; i<=N; i++) psum[i] = psum[i-1] + arr[i-1];
    
    ll sum = 0;
    for(int i=1; i<=N; i++){
        sum = max(psum[i] * i, sum + arr[i-1]);
    }
    
    return sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    N = 5;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-10, 10);
    
    vector<int> arr(N);
    ll ans1 = 0, ans2 = 0;
    while(ans1 == ans2){
        for(int i=0; i<N; i++) arr[i] = dis(gen);
        ans1 = solve1(arr);
        ans2 = solve2(arr);
    }

    solve1(arr);
    for(auto i: arr) cout << i << ' ';
    cout << '\n' << ans1 << ' ' << ans2 << '\n';

    return 0;
}