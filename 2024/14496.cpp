#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int s, e; cin >> s >> e;
    int N, M; cin >> N >> M;
    vector<int> adj[N+1];
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pii> que;
    vector<bool> visited(N+1);
    que.push({s, 0});
    visited[s] = true;
    while(!que.empty()){
        auto [cur, cnt] = que.front();
        que.pop();
        if(cur == e){
            cout << cnt << '\n';
            return 0;
        }
        for(auto next: adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                que.push({next, cnt + 1});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}