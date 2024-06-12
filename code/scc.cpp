#include <bits/stdc++.h>
using namespace std;

struct strongly_connected{
    vector<vector<int>> adj;
    
    void init(int n){
        adj.clear();
        adj.resize(n+1);
    }
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    
    vector<int> dfn, sccId;
    int pv, scc_cnt;
    stack<int> st;
    int dfs(int cur){
        int ret = dfn[cur] = ++pv;
        st.push(cur);
        for(auto next: adj[cur]){
            if(dfn[next] == -1) ret = min(ret, dfs(next));
            else if(sccId[next] == -1) ret = min(ret, dfn[next]);
        }
        if(ret == dfn[cur]){
            while(1){
                int t = st.top(); st.pop();
                sccId[t] = scc_cnt;
                if(t == cur) break;
            }
            scc_cnt++;
        }
        return ret;
    }

    vector<vector<int>> dag;
    void get_scc(int n){
        dfn = vector<int>(n+1, -1);
        sccId = vector<int>(n+1, -1);
        pv = scc_cnt = 0;
        for(int i=1; i<=n; i++){
            if(dfn[i] == -1) dfs(i);
        }
        dag.resize(scc_cnt);
        for(int i=1; i<=n; i++){
            for(auto next: adj[i]){
                if(sccId[i] != sccId[next]){
                    dag[i].push_back(next);
                }
            }
        }
    }
}scc;