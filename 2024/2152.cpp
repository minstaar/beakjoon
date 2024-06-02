#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10010], cnt;
int discover[10010], scc[10010], id, scc_cnt;
stack<int> st;

int dfs(int cur)
{
    int parent = discover[cur] = ++id;
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
        int c = 0;
        while(1){
            int t = st.top();
            st.pop();
            scc[t] = scc_cnt;
            c++;
            if(t == cur) break;
        }
        cnt.push_back(c);
        scc_cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, s, e; cin >> N >> M >> s >> e;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
    for(int i=1; i<=N; i++){
        if(discover[i] == -1) dfs(i);
    }
    vector<int> dag[scc_cnt];
    for(int i=1; i<=N; i++){
        for(auto next: adj[i]){
            if(scc[i] != scc[next]){
                dag[scc[i]].push_back(scc[next]);
            }
        }
    }

    vector<int> dp(scc_cnt);
    dp[scc[s]] = cnt[scc[s]];
    for(int i=scc[s]; i>=scc[e]; i--){
        if(dp[i] == 0) continue;
        for(auto next: dag[i]){
            dp[next] = max(dp[next], dp[i] + cnt[next]);
        }
    }
    cout << dp[scc[e]] << '\n';
    
    return 0;
}