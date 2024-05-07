#include <iostream>
#include <vector>
using namespace std;

int query[100010], ans[100010];
bool visited[100010];
vector<int> adj[100010];

void DFS(int cur, int cost)
{
    for(auto next: adj[cur]){
        if(!visited[next]){
            visited[next] = true;
            DFS(next, cost + query[cur]);
        }
    }
    ans[cur] = cost + query[cur];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++){
        int a; cin >> a;
        adj[a].push_back(i);
    }
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        query[a] += b;
    }
    visited[1] = true;
    DFS(1, query[1]);

    for(int i=1; i<=N; i++) cout << ans[i] << " ";

    return 0;
}