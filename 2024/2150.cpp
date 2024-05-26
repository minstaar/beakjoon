#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int V, E;
int discover[10010], id, finished[10010], cnt;
vector<int> adj[10010];
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
        else if(finished[next] == -1){
            parent = min(parent, discover[next]);
        }
    }
    if(parent == discover[cur]){
        vector<int> tmp;
        while(1){
            int t = st.top();
            st.pop();
            finished[t] = cnt;
            tmp.push_back(t);
            if(t == cur) break;
        }
        sort(tmp.begin(), tmp.end());
        res.push_back(tmp);
        cnt++;
    }
    return parent;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(discover, -1, sizeof(discover));
    memset(finished, -1, sizeof(finished));
    for(int i=1; i<=V; i++){
        if(discover[i] == -1){
            dfs(i);
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << '\n';
    for(int i=0; i<cnt; i++){
        for(auto x: res[i]) cout << x << ' ';
        cout << -1 << '\n';
    }

    return 0;
}