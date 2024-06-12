#include <bits/stdc++.h>
using namespace std;

struct strongly_connected{
    vector<vector<int>> adj;
    
    void init(int n){
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }
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
            if(!dfn[next]) ret = min(ret, dfs(next));
            else if(!sccId[next]) ret = min(ret, dfn[next]);
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

    void get_scc(int n){
        dfn.clear(); dfn.resize(n+1);
        sccId.clear(); sccId.resize(n+1);
        pv = scc_cnt = 0;
        for(int i=1; i<=n; i++){
            if(!dfn[i]) dfs(i);
        }
    }
}scc;

struct twosat{
    strongly_connected scc;
    int n;
    vector<int> res;

    void init(int _n){
        scc.init(n*2+1);
        n = _n;
    }
    
    int Not(int x) {return x > n ? x - n : x + n;}

    void addEdge(int u, int v){
        if(u < 0) u = n - u;
        if(v < 0) v = n - v;
        scc.addEdge(Not(u), v);
        scc.addEdge(Not(v), u);
    }

    bool satisfy(){
        res.resize(n+1);
        for(int i=1; i<=n; i++){
            if(scc.sccId[i] == scc.sccId[Not(i)]){
                return false;
            }
        }
        for(int i=1; i<=n; i++){
            res[i] = (scc.sccId[i] < scc.sccId[Not(i)]);
        }
        return true;
    }
}twosat;