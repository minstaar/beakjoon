#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define ll long long
#define INF 1e14
using namespace std;

typedef pair<ll, ll> pll;

int V, E;
bool cycle;
vector<pll> adj[110];
vector<int> rev[110];
bool visited[110];

vector<int> bellmanFord(int src)
{
    vector<ll> upper(V+1, INF);
    vector<int> parent(V+1);
    upper[src] = 0;
    bool updated;

    for(int i=1; i<=V; i++){
        updated = false;
        for(int cur=1; cur<=V; cur++){
            for(auto x: adj[cur]){
                int next = x.first;
                ll cost = x.second;
                if(upper[cur] != INF && upper[next] > upper[cur] + cost){
                    upper[next] = upper[cur] + cost;
                    updated = true;
                    parent[next] = cur;
                    if(i == V && visited[next]) cycle = true;
                }
            }
        }
        if(!updated) break;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, -w});
        rev[b].push_back(a);
    }

    queue<int> que;
    que.push(V);
    visited[V] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto x: rev[cur]){
            if(!visited[x]){
                visited[x] = true;
                que.push(x);
            }
        }
    }

    auto path = bellmanFord(1);

    if(cycle) cout << -1 << '\n';

    else{
        stack<int> ans;
        int cur = V;
        while(cur >= 1){
            ans.push(cur);
            cur = path[cur];
        }
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }
    
    return 0;
}