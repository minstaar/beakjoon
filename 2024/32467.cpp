#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, X;
ll K;
vector<pii> arr(100010);

bool solve(int score)
{
    int cnt = 0;
    ll sum = 0;
    priority_queue<ll> pq;
    for(int i=0; i<N; i++){
        if(arr[i].first > score){
            ll tmp = 1LL * arr[i].second * (arr[i].first - score);
            pq.push(tmp);
            sum += tmp;
        }
        else break;
    }

    for(int i=1; i<X; i++){
        if(pq.empty()) break;
        sum -= pq.top();
        pq.pop();
    }

    return sum < K;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> X;
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), greater<>());

    int l = 0, r = arr[0].first;
    while(l <= r){
        int m = l + r >> 1;
        if(solve(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l << '\n';

    return 0;
}