#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N, M, S;
int A[500010], B[500010];
vector<int> adj[500010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> S;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll val = B[S];
    queue<int> que;
    vector<bool> visited(N+1, false);
    priority_queue<pii> candidate;
    que.push(S);
    visited[S] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: adj[cur]){
            if(visited[next]) continue;
            if(val < A[next]){
                candidate.push({-A[next], next});
            }
            else{
                val += B[next];
                visited[next] = true;
                que.push(next);
                while(candidate.size()){
                    if(val >= -candidate.top().first){
                        auto [tmp, idx] = candidate.top();
                        candidate.pop();
                        val += B[idx];
                        visited[idx] = true;
                        que.push(idx);
                    }
                    else break;
                }
            }
        }
    }
    cout << val << '\n';

    return 0;
}