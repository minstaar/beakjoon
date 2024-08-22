#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, K, M;
vector<int> adj[101010], visited(101010);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> M;
    for(int i=1; i<=M; i++){
        for(int j=0; j<K; j++){
            int a; cin >> a;
            adj[i+N].push_back(a);
            adj[a].push_back(i + N);
        }
    }

    queue<pii> que;
    que.push({1, 1});
    bool flag = false;
    while(!que.empty()){
        auto [cur, cost] = que.front();
        que.pop();
        if(cur == N){
            cout << cost << '\n';
            flag = true;
            break;
        }
        for(auto next: adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                if(next <= N) que.push({next, cost + 1});
                else que.push({next, cost});
            }
        }
    }
    if(!flag) cout << "-1\n";

    return 0;
}