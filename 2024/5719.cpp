#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int N, M;
int adj[510][510];
vector<int> parent[510];

int dijkstra(int s, int e)
{
    vector<int> dist(N, INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();
        if(dist[cur] < cost) continue;
        for(int i=0; i<N; i++){
            if(adj[cur][i] == 0) continue;
            if(dist[i] > cost + adj[cur][i]){
                dist[i] = cost + adj[cur][i];
                parent[i].clear();
                parent[i].push_back(cur);
                pq.push({dist[i], i});
            }
            else if(dist[i] == cost + adj[cur][i]){
                parent[i].push_back(cur);
            }
        }
    }
    if(dist[e] == INF) return -1;
    else return dist[e];
}

void shortest_path_delet(int e)
{
    queue<int> que;
    vector<bool> visit(N);
    que.push(e);
    visit[e] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: parent[cur]){
            adj[next][cur] = 0;
            if(!visit[next]){
                visit[next] = true;
                que.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        memset(adj, 0, sizeof(adj));
        for(int i=0; i<N; i++){
            parent[i].clear();
        }
        int s, e; cin >> s >> e;
        for(int i=0; i<M; i++){
            int u, v, c; cin >> u >> v >> c;
            adj[u][v] = c;
        }
        dijkstra(s, e);
        shortest_path_delet(e);
        cout << dijkstra(s, e) << '\n';
    }

    return 0;
}