#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adj[20010];
vector<vector<int>> res;
int discover[20010], scc[20010], id, scc_cnt;
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
            scc[t] = scc_cnt;
            tmp.push_back(t);
            if(t == cur) break;
        }
        res.push_back(tmp);
        scc_cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
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

    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
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
    if(flag) cout << 0 << '\n';
    else{
        cout << 1 << '\n';
        vector<int> ans(N*2+1, -1);
        for(int i=0; i<scc_cnt; i++){
            for(auto x: res[i]){
                if(ans[x] != -1) continue;
                if(x <= N){
                    ans[x] = 1;
                    ans[x+N] = 0;
                }
                else{
                    ans[x-N] = 0;
                    ans[x] = 1;
                }
            }
        }
        for(int i=1; i<=N; i++) cout << ans[i] << ' ';
        cout << '\n';

        return 0;
    }
}