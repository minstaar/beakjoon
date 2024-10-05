#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Data
{
    ll a, b;
    bool operator < (const Data &o) const{
        if(a == o.a) return a < o.a;
        return b < o.b;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, X; ll K; cin >> N >> K >> X;
    vector<pll> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](pll a, pll b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    });

    priority_queue<Data> pq;
    ll a = arr[X-1].first, b = arr[X-1].second;
    for(int i=X; i<N; i++){
        if(arr[i].first == a){
            b += arr[i].second;
        }
        else{
            pq.push({a, b});
            a = arr[i].first;
            b = arr[i].second;
        }
    }
    pq.push({a, b});

    while(pq.size() > 1 && K > 0){
        auto [a, b] = pq.top();
        pq.pop();
        
        if((a - pq.top().a) * b <= K){
            K -= (a - pq.top().a) * b;
            auto [na, nb] = pq.top();
            pq.pop();
            pq.push({na, nb + b});
        }
    }

    cout << pq.top().a << '\n';

    return 0;
}