#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[500010];
int discover[500010], scc[500010], id, scc_cnt;
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

    int N; cin >> N;
    const int MAX = N * 5;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(arr[i] == 0){
            int a2 = 5 * i + 2, not_a2 = a2 + MAX; //arr[i]의 k번째 비트 (arr[i] >> k) & 1
            int a3 = 5 * i + 3, not_a3 = a3 + MAX;
            int a4 = 5 * i + 4, not_a4 = a4 + MAX;
            adj[a4].push_back(not_a3);
            adj[a3].push_back(not_a4);
            adj[not_a4].push_back(a3);
            adj[not_a3].push_back(a4);
            adj[a4].push_back(not_a2);
            adj[a2].push_back(not_a4);
        }
        else{
            for(int j=0; j<5; j++){
                int a = 5 * i + j;
                int not_a = a + MAX;
                if((arr[i] >> j) & 1){
                    adj[not_a].push_back(a);
                }
                else{
                    adj[a].push_back(not_a);
                }
            }
        }
    }
    int M; cin >> M;
    for(int i=0; i<M; i++){
        char t; cin >> t;
        int x, y, z; cin >> x >> y >> z;
        if(t == '&'){
            for(int j=0; j<5; j++){
                int a = 5 * (x - 1) + j;
                int b = 5 * (y - 1) + j;
                int not_a = a + MAX, not_b = b + MAX;
                if((z >> j) & 1){
                    adj[not_a].push_back(a);
                    adj[not_b].push_back(b);
                }
                else{
                    adj[a].push_back(not_b);
                    adj[b].push_back(not_a);
                }
            }
        }
        else{
            for(int j=0; j<5; j++){
                int a = 5 * (x - 1) + j;
                int b = 5 * (y - 1) + j;
                int not_a = a + MAX, not_b = b + MAX;
                if((z >> j) & 1){
                    adj[not_a].push_back(b);
                    adj[not_b].push_back(a);
                }
                else{
                    adj[a].push_back(not_a);
                    adj[b].push_back(not_b);
                }
            }
        }
    }

    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
    for(int i=0; i<MAX*2; i++){
        if(discover[i] == -1) dfs(i);
    }
    bool flag = false;
    for(int i=0; i<MAX; i++){
        if(scc[i] == scc[i+MAX]){
            flag = true;
            break;
        }
    }
    if(flag) cout << 0 << '\n';
    else{
        cout << 1 << '\n';
        for(int i=0; i<N; i++){
            int res = 0;
            for(int j=0; j<5; j++){
                if(scc[5*i+j] < scc[5*i+j+MAX]){
                    res |= (1 << j);
                }
            }
            cout << res << ' ';
        }
        cout << '\n';
    }

    return 0;
}