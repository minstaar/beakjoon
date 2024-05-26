#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int discover[100010], scc[100010], inDegree[100010], id, cnt;
vector<int> adj[100010];
stack<int> st;

int dfs(int cur)
{
    discover[cur] = ++id;
    int parent = discover[cur];
    st.push(cur);
    for(auto next: adj[cur]){
        if(discover[next] == -1){
            parent = min(parent, dfs(next));
        }
        else if(scc[next] == -1){
            parent = min(parent, discover[next]);
        }
    }
    if(parent == discover[cur]){
        while(1){
            int t = st.top();
            st.pop();
            scc[t] = cnt;
            if(t == cur) break;
        }
        cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        memset(discover, -1, sizeof(discover));
        memset(scc, -1, sizeof(scc));
        memset(inDegree, 0, sizeof(inDegree));
        for(int i=1; i<=N; i++) adj[i].clear();
        id = cnt = 0;
        for(int i=0; i<M; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int i=1; i<=N; i++){
            if(discover[i] == -1){
                dfs(i);
            }
        }
        for(int i=1; i<=N; i++){
            for(auto next: adj[i]){
                if(scc[next] == scc[i]) continue;
                inDegree[scc[next]]++;
            }
        }
        int ans = 0;
        for(int i=0; i<cnt; i++){
            if(!inDegree[i]) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}