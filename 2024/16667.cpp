#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int discover[200010], sccId[200010], id, scc_cnt;
vector<int> adj[200010];
vector<vector<int>> scc;
string str;
stack<int> st;

int dfs(int cur)
{
    int parent = discover[cur] = ++id;
    st.push(cur);
    for(auto next: adj[cur]){
        if(discover[next] == -1){
            parent = min(parent, dfs(next));
        }
        else if(sccId[next] == -1){
            parent = min(parent, discover[next]);
        }
    }
    if(parent == discover[cur]){
        //vector<int> tmp;
        while(1){
            int t = st.top();
            st.pop();
            sccId[t] = scc_cnt;
            //tmp.push_back(t);
            if(t == cur) break;
        }
        //scc.push_back(tmp);
        scc_cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M >> str;
        memset(discover, -1, sizeof(discover[0]) * (N + 1) * 2);
        memset(sccId, -1, sizeof(sccId[0]) * (N + 1) * 2);
        id = scc_cnt = 0;
        for(int i=1; i<=N*2; i++) adj[i].clear();
        //scc.clear();
        for(int i=0; i<M; i++){
            int u, v; cin >> u >> v;
            int not_u, not_v;
            if(u < 0){
                not_u = -u;
                u = N - u;
            }
            else not_u = N + u;
            if(v < 0){
                not_v = -v;
                v = N - v;
            }
            else not_v = N + v;
            adj[not_u].push_back(v);
            adj[not_v].push_back(u);
        }
        
        for(int i=1; i<=N*2; i++){
            if(discover[i] == -1) dfs(i);
        }

        bool flag = true;
        //Condition 1: x and ~x are in the different SCC
        for(int i=1; i<=N; i++){
            if(sccId[i] == sccId[i+N]){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << "FALSE" << '\n';
            continue;
        }

        //Condition 2: In all SCC, universal vertex xi comes first from every existencial vertex xj (i < j)
        vector<int> has(scc_cnt, -1), from(scc_cnt), to(scc_cnt);
        for(int i=N; i>=1; i--){
            if(has[sccId[i]] != -1 || has[sccId[i+N]] != -1){
                flag = false;
                break;
            }
            if(str[i-1] == 'A'){
                has[sccId[i]] = i;
                has[sccId[i+N]] = i + N;
            }
        }
        if(!flag){
            cout << "FALSE" << '\n';
            continue;
        }

        //Condition 3: Any universial vertex (x and its negation) can reachable
        vector<int> dag[scc_cnt];
        for(int i=0; i<scc_cnt; i++){
            if(has[i] != -1) from[i] = to[i] = 1;
        }
        for(int i=1; i<=N*2; i++){
            for(auto next: adj[i]){
                if(sccId[i] != sccId[next]){
                    dag[sccId[i]].push_back(sccId[next]);
                }
            }
        }
        for(int i=0; i<scc_cnt; i++){
            bool reach = false;
            for(auto next: dag[i]) reach |= to[next];
            if(reach && to[i]){
                flag = false;
                break;
            }
            to[i] |= reach;
        }
        if(!flag){
            cout << "FALSE" << '\n';
            continue;
        }

        /*
        for(int i=scc_cnt-1; i>=0; i--){
            for(auto next: dag[i]) from[next] |= from[i];
        }
        vector<int> arr(N+1, -1);
        for(int i=0; i<scc_cnt; i++){
            if(has[i]!=-1){
                for(auto v: scc[i]){
                    if(v > N) arr[v-N] = (has[i] > N ? 1 : 0);
                    else arr[v] = (has[i] <= N ? 1 : 0);
                }
            }
            else if(from[i]){
                for(auto v: scc[i]){
                    if(v > N) arr[v-N] = 0;
                    else arr[v] = 1;
                }
            }
            else if(to[i]){
                for(auto v: scc[i]){
                    if(v > N) arr[v-N] =1;
                    else arr[v] = 0;
                }
            }
        }
        for(int i=1; i<=N; i++){
            if(arr[i] == -1) arr[i] = (sccId[i+N] < sccId[i]);
        }
        */
        cout << "TRUE" << '\n';
    }
    
    return 0;
}