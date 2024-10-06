#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
using ld = long double;
using pii = pair<int, int>;

ld INF = 1e18;
vector<ld> dist(2010, INF);
vector<pair<int, ld>> adj[2010];
vector<pii> arr(2010);

ld getDist(pair<ld, ld> a, pair<ld, ld> b)
{
    ld x = abs(a.first - b.first);
    ld y = abs(a.second - b.second);
    return sqrt(x * x + y * y);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int A, B; cin >> A >> B;
    int N; cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            ld d = getDist(arr[i], arr[j]);
            d = max((ld)0, d - 2);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }
    for(int i=1; i<=N; i++){
        ld d = getDist({0, 0}, arr[i]);
        d = max((ld)0, d - 1);
        adj[0].push_back({i, d});
        d = getDist(arr[i], {A, B});
        d = max((ld)0, d - 1);
        adj[i].push_back({N + 1, d});
    }
    adj[0].push_back({N + 1, getDist({0, 0}, {A, B})});

    priority_queue<pair<ld, int>, vector<pair<ld, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        auto [curCost, cur] = pq.top();
        pq.pop();
        curCost = -curCost;
        if(curCost > dist[cur]) continue;
        for(auto [next, nextCost]: adj[cur]){
            if(dist[next] > dist[cur] + nextCost){
                dist[next] = dist[cur] + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }

    cout << fixed << setprecision(9) << dist[N+1] << '\n';

    return 0;
}
