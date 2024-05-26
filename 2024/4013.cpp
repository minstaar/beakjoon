#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int discover[500010], scc[500010], cost[500010];
int id, sccCnt;
vector<int> adj[500010];
stack<int> st;
bool check[500010];

struct Node
{
    ll cost;
    bool check;
};
vector<Node> dag;

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
        ll tmp = 0;
        bool flag = false;
        while(1){
            int t = st.top();
            st.pop();
            scc[t] = sccCnt;
            tmp += cost[t];
            if(check[t]) flag = true;
            if(t == cur) break;
        }
        dag.push_back({tmp, flag});
        sccCnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=N; i++) cin >> cost[i];
    int s, p; cin >> s >> p;
    for(int i=0; i<p; i++){
        int a; cin >> a;
        check[a] = true;
    }
    
    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
    for(int i=1; i<=N; i++){
        if(discover[i] == -1) dfs(i);
    }
    
    vector<int> path[sccCnt];
    vector<int> inDegree(sccCnt);
    vector<ll> dp(sccCnt);
    for(int i=1; i<=N; i++){
        for(auto next: adj[i]){
            if(scc[i] == scc[next]) continue;
            path[scc[i]].push_back(scc[next]);
            inDegree[scc[next]]++;
        }
    }
    
    bool flag = false;
    queue<int> que;
    for(int i=0; i<sccCnt; i++){
        if(inDegree[i] == 0){
            que.push(i);
        }
    }
    dp[scc[s]] = dag[scc[s]].cost;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(cur == scc[s]) flag = true;
        for(auto next: path[cur]){
            inDegree[next]--;
            if(inDegree[next] == 0){
                que.push(next);
            }
            if(flag) dp[next] = max(dp[next], dp[cur] + dag[next].cost);
        }
    }
    ll ans = 0;
    for(int i=0; i<sccCnt; i++){
        if(dag[i].check) ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}