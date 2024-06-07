#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<int> adj[1010];
int dfn[1010], id;
bool cut[1010];
stack<pii> st;
int ans1, ans2, p, q;

int dfs(int prev, int cur, bool isRoot)
{
    int ret = dfn[cur] = ++id;
    int child = 0;
    for(auto next: adj[cur]){
        if(next == prev) continue;
        if(dfn[cur] > dfn[next]){
            st.push({cur, next});
        }
        if(dfn[next] > 0){
            ret = min(ret, dfn[next]);
        }
        else{
            child++;
            int low = dfs(cur, next, false);
            if(low >= dfn[cur]){
                if(!isRoot && !cut[cur]){
                    cut[cur] = true;
                    ans1++;
                }
                if(low > dfn[cur]) ans2++;
                p++;
                vector<pii> tmp;
                while(1){
                    pii t = st.top();
                    st.pop();
                    tmp.push_back(t);
                    if(t == make_pair(cur, next)) break;
                }
                q = max(q, (int)tmp.size());
            }
            ret = min(ret, low);
        }
    }
    if(isRoot && child >= 2 && !cut[cur]){
        cut[cur] = true;    
        ans1++;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        memset(dfn, 0, sizeof(dfn));
        memset(cut, false, sizeof(cut));
        for(int i=1; i<=N; i++) adj[i].clear();
        id = 0;
        ans1 = ans2 = p = q = 0;
        for(int i=0; i<M; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1; i<=N; i++){
            if(dfn[i] == 0) dfs(0, i, true);
        }

        int gcd = __gcd(p, q);
        cout << ans1 << ' ' << ans2 << ' ' << p/gcd << ' ' << q/gcd << '\n';
    }

    return 0;
}