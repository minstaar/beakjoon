#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
using pii = pair<int, int>;

double INF = 1e18;
vector<double> dist(2010, INF);
vector<pair<int, double>> adj[2010];
vector<pii> arr(2010);

double getDist(pair<double, double> a, pair<double, double> b)
{
    double x = abs(a.first - b.first);
    double y = abs(a.second - b.second);
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
            double d = getDist(arr[i], arr[j]);
            d = max((double)0, d - 2);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }
    for(int i=1; i<=N; i++){
        double d = getDist({0, 0}, arr[i]);
        d = max((double)0, d - 1);
        adj[0].push_back({i, d});
        d = getDist(arr[i], {A, B});
        d = max((double)0, d - 1);
        adj[i].push_back({N + 1, d});
    }
    adj[0].push_back({N + 1, getDist({0, 0}, {A, B})});

    priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
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
