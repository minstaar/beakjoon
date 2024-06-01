#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int discover[2010], scc[2010], id, scc_cnt;
vector<int> adj[2010];
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
        while(1){
            int t = st.top();
            st.pop();
            scc[t] = scc_cnt;
            if(t == cur) break;
        }
        scc_cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    while(cin >> N >> M){
        memset(discover, -1, sizeof(discover));
        memset(scc, -1, sizeof(scc));
        for(int i=1; i<=N*2; i++) adj[i].clear();
        id = scc_cnt = 0;
        for(int i=0; i<M; i++){
            int a, b; cin >> a >> b;
            int not_a, not_b;
            if(a < 0){
                not_a = -a;
                a = N - a;
            }
            else not_a = N + a;
            if(b < 0){
                not_b = -b;
                b = N - b;
            }
            else not_b = N + b;

            adj[not_a].push_back(b);
            adj[not_b].push_back(a);
        }

        for(int i=1; i<=N*2; i++){
            if(discover[i] == -1) dfs(i);
        }
        bool flag = false;
        for(int i=1; i<=N; i++){
            if(scc[i] == scc[i+N]){
                flag = true;
                break;
            }
        }
        flag ? cout << 0 << '\n' : cout << 1 << '\n';
    }

    return 0;
}