#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<int> adj[100010];
stack<pii> st;
vector<vector<pii>> bcc;
int dfn[100010], id;

int dfs(int prev, int cur)
{
    int ret = dfn[cur] = ++id;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        if(dfn[cur] > dfn[next]){
            st.push({cur, next});
        }
        if(dfn[next] > 0){
            ret = min(ret, dfn[next]);
        }
        else{
            int low = dfs(cur, next);
            if(low >= dfn[cur]){
                vector<pii> tmp;
                while(1){
                    pii t = st.top();
                    st.pop();
                    tmp.push_back(t);
                    if(t == make_pair(cur, next)) break;
                }
                bcc.push_back(tmp);
            }
            ret = min(ret, low);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++){
        if(dfn[i] == 0) dfs(0, i);
    }

    bool flag = true;
    vector<int> check(N+1, -1);
    for(int i=0; i<bcc.size(); i++){
        if(bcc[i].size()>=3){
            int vertex = 0;
            for(auto [u, v]: bcc[i]){
                if(check[u] == -1){
                    check[u] = i;
                    vertex++;
                }
                if(check[v] == -1){
                    check[v] = i;
                    vertex++;
                }
                if(check[u] != i || check[v] != i){
                    flag = false;
                    break;
                }
            }
            if(vertex != bcc[i].size()){
                flag = false;
            }
            if(!flag) break;
        }
    }
    if(flag) cout << "Cactus" << '\n';
    else cout << "Not cactus" << '\n';

    return 0;
}