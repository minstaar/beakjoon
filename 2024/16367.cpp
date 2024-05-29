#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10010];
int discover[10010], scc[10010], id, scc_cnt;
stack<int> st;
vector<vector<int>> component;

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
        component.push_back(tmp);
        scc_cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int K, N; cin >> K >> N;
    for(int i=0; i<N; i++){
        int x1, x2, x3;
        char a1, a2, a3;
        cin >> x1 >> a1 >> x2 >> a2 >> x3 >> a3;
        int not_x1, not_x2, not_x3;
        if(a1 == 'B'){
            not_x1 = x1;
            x1 = K + x1;
        }
        else not_x1 = K + x1;
        if(a2 == 'B'){
            not_x2 = x2;
            x2 = K + x2;
        }
        else not_x2 = K + x2;
        if(a3 == 'B'){
            not_x3 = x3;
            x3 = K + x3;
        }
        else not_x3 = K + x3;

        adj[not_x1].push_back(x2);
        adj[not_x1].push_back(x3);
        adj[not_x2].push_back(x1);
        adj[not_x2].push_back(x3);
        adj[not_x3].push_back(x1);
        adj[not_x3].push_back(x2);
    }

    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
    for(int i=1; i<=K*2; i++){
        if(discover[i] == -1) dfs(i);
    }

    bool flag = false;
    for(int i=1; i<=K; i++){
        if(scc[i] == scc[i+K]){
            flag = true;
            break;
        }
    }
    if(!flag){
        for(int i=1; i<=K; i++){
            cout << (scc[i] < scc[i+K] ? 'R' : 'B');
        }
        cout << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}
