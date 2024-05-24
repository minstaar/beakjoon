#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

int N, M;
vector<pii> adj[1010];
vector<int> rev[1010], dist(1010);
bool cycle[1010], reached[1010];

void spfa(int src)
{
    queue<int> que;
    vector<int> inQue(N, INF);
    que.push(src);
    inQue[src] = -1;
    for(int cnt=0; !que.empty() && cnt<=N; cnt++){
        for(int i=que.size()-1; i>=0; i--){
            int cur = que.front();
            que.pop();
            for(auto [next, nextCost]: adj[cur]){
                if(dist[next] > dist[cur] + nextCost){
                    dist[next] = dist[cur] + nextCost;
                    if(inQue[next] != cnt){
                        que.push(next);
                        inQue[next] = cnt;
                    }
                    if(cnt == N) cycle[next] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int k=1; k<=T; k++){
        cin >> N >> M;
        for(int i=0; i<N; i++){
            adj[i].clear();
            rev[i].clear();
            dist[i] = INF;
        }
        memset(reached, false, sizeof(reached));
        memset(cycle, false, sizeof(cycle));
        for(int i=0; i<M; i++){
            int u, v, c; cin >> u >> v >> c;
            adj[u].push_back({v, c});
            rev[v].push_back(u);
        }

        queue<int> que;
        que.push(0);
        reached[0] = true;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto next: rev[cur]){
                if(!reached[next]){
                    reached[next] = true;
                    que.push(next);
                }
            }
        }

        dist[0] = 0;
        spfa(0);
        bool flag = false;
        for(int i=0; i<N; i++){
            if(cycle[i] && reached[i]) flag = true;
        }
        cout << "Case #" << k << ": ";
        if(flag) cout << "possible" << '\n';
        else cout << "not possible" << '\n';
    }

    return 0;
}