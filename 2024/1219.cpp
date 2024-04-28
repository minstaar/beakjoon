#include <iostream>
#include <vector>
#include <queue>
#define INF 1e14
#define ll long long
using namespace std;

typedef pair<ll, ll> pll;
ll N, M, S, E;
vector<pll> adj[55];
vector<ll> rev[55];
long long v[55];
bool reached[55];

void bellmanFord(int src)
{
    vector<ll> upper(N, INF);
    bool updated;
    upper[src] = 0;
    for(int i=1; i<=N; i++){
        updated = false;
        for(int cur=0; cur<N; cur++){
            for(auto x: adj[cur]){
                int next = x.first;
                ll cost = x.second;
                if(upper[cur] != INF && upper[next] > upper[cur] + cost){
                    upper[next] = upper[cur] + cost;
                    updated = true;
                    if(i == N && reached[next]){
                        cout << "Gee" << '\n';
                        return;
                    }
                }
            }
        }
        if(!updated) break;
    }
    if(upper[E] == INF){
        cout << "gg" << '\n';
    }
    else{
        cout << -upper[E] + v[E] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S >> E >> M;
    for(int i=0; i<M; i++){
        ll a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        rev[b].push_back(a);
    }
    for(int i=0; i<N; i++){
        cin >> v[i];
        for(auto& x: adj[i]){
            x.second -= v[i];
        }
    }

    queue<int> que;
    que.push(E);
    reached[E] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto x: rev[cur]){
            if(!reached[x]){
                reached[x] = true;
                que.push(x);
            }
        }
    }
    
    bellmanFord(S);

    return 0;
}