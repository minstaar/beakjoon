#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k; cin>>n>>k;
    vector<pair<int, int>> arr(n);
    vector<int> bag(k);
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=0; i<k; i++){
        cin>>bag[i];
    }

    sort(arr.begin(), arr.end());
    sort(bag.begin(), bag.end());

    int idx = 0;
    long long ans = 0;
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        while(idx < n && bag[i] >= arr[idx].first) {pq.push(arr[idx].second); idx++;}
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout<<ans;

    return 0;
}