#include <bits/stdc++.h>
using namespace std;

struct strongly_connected{
    vector<vector<int>> adj, dag;
    vector<int> dfn, sccId;
    int pv, scc_cnt;
    stack<int> st;
    
    strongly_connected(int _n): adj(_n+1) {}
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    
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

    void get_scc(int n){
        dfn = vector<int>(n+1, -1);
        sccId = vector<int>(n+1, -1);
        pv = scc_cnt = 0;
        for(int i=1; i<=n; i++){
            if(dfn[i] == -1) dfs(i);
        }
        dag = vector<vector<int>>(scc_cnt);
        for(int i=1; i<=n; i++){
            for(auto next: adj[i]){
                if(sccId[i] != sccId[next]){
                    dag[sccId[i]].push_back(sccId[next]);
                }
            }
        }
    }
};

struct TwoSat{
    strongly_connected scc;
    int n;
    vector<int> res;

    TwoSat(int _n): n(_n), scc(_n*2+1) {}
    
    int Not(int x) {return x > n ? x - n : x + n;}

    void addEdge(int u, int v){
        if(u < 0) u = n - u;
        if(v < 0) v = n - v;
        scc.addEdge(Not(u), v);
        scc.addEdge(Not(v), u);
    }

    bool satisfy(){
        scc.get_scc(n*2);
        res.clear();
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
};