#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int discover[100010], scc[100010], inDegree[100010];
int id, sccCnt;
vector<int> adj[100010];
vector<vector<int>> res;
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
        vector<int> tmp;
        while(1){
            int t = st.top();
            st.pop();
            tmp.push_back(t);
            scc[t] = sccCnt;
            if(t == cur) break;
        }
        sccCnt++;
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
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
        id = sccCnt = 0;
        for(int i=0; i<N; i++) adj[i].clear();
        res.clear();

        for(int i=0; i<M; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }
        for(int i=0; i<N; i++){
            if(discover[i] == -1) dfs(i);
        }

        for(int i=0; i<N; i++){
            for(auto next: adj[i]){
                if(scc[next] == scc[i]) continue;
                inDegree[scc[next]]++;
            }
        }
        int ans = -1;
        bool flag = false;
        for(int i=0; i<sccCnt; i++){
            if(inDegree[i] == 0){
                if(flag){
                    flag = false;
                    break;
                }
                ans = i;
                flag = true;
            }
        }
        if(!flag) cout << "Confused" << '\n';
        else{
            for(auto x: res[ans]) cout << x << '\n';
        }
        cout << '\n';
    }

    return 0;
}