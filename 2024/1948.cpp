#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> adj[10010];
int s, e, inDegree[10010], dist[10010];
vector<int> path[10010];
bool visited[10010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        inDegree[v]++;
    }
    cin >> s >> e;

    queue<int> que;
    que.push(s);
    dist[s] = 0;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto [next, nextCost]: adj[cur]){
            inDegree[next]--;
            if(inDegree[next] == 0) que.push(next);
            if(dist[cur] + nextCost > dist[next]){
                dist[next] = dist[cur] + nextCost;
                path[next].clear();
                path[next].push_back(cur);
            }
            else if(dist[cur] + nextCost == dist[next]){
                path[next].push_back(cur);
            }
        }
    }

    int ans = 0;
    que.push(e);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: path[cur]){
            if(!visited[next]){
                visited[next] = true;
                que.push(next);
            }
            ans++;
        }
    }
    
    cout << dist[e] << '\n' << ans << '\n';

    return 0;

}