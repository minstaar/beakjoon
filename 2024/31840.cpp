#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


typedef long long ll;

int N, M;
vector<pair<int, int>> adj[300010];
ll w[300010];
int visited[300010], useless[300010];
ll ans;

bool BFS(int pos)
{
    queue<int> que;
    que.push(1);
    visited[1] = pos;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto [next, i]: adj[cur]){
            if(visited[next] == pos || useless[i]) continue;
            if(w[i] >> pos & 1) continue;
            que.push(next);
            visited[next] = pos;
        }
    }
    return visited[N] == pos;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int s, e;
        cin >> s >> e >> w[i];
        adj[s].push_back({e, i});
        adj[e].push_back({s, i});
    }

    memset(visited, -1, sizeof(visited));
    for(int i=59; i>=0; i--){
        if(!BFS(i)){
            ans |= 1LL << i;
        }
        else{
            for(int j=1; j<=M; j++){
                if(w[j] >> i & 1) useless[j] = 1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
