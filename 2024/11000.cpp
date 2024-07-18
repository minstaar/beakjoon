#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<pii> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    priority_queue<pii, vector<pii>, greater<>> pq;
    int res = 0;
    for(int i=0; i<N; i++){
        if(!pq.empty() && pq.top().first <= arr[i].first) pq.pop();
        pq.push({arr[i].second, arr[i].first});
        res = max(res, (int)pq.size());
    }
    cout << res << '\n';

    return 0;
}