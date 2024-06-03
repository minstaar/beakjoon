#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[2500];
int discover[2500], scc[2500], id, scc_cnt;
stack<int> st;
vector<vector<int>> res;

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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    map<string, int> hash;
    int key = 0;
    for(int i=0; i<N; i++){
        string a; cin >> a;
        if(hash.find(a) == hash.end()){
            hash[a] = ++key;
        }
        int k; cin >> k;
        for(int j=0; j<k; j++){
            string b; cin >> b;
            if(hash.find(b) == hash.end()){
                hash[b] = ++key;
            }
            adj[hash[b]].push_back(hash[a]);
        }
    }
    string tg; cin >> tg;
    
    memset(discover, -1, sizeof(discover));
    memset(scc, -1, sizeof(scc));
    for(auto x: hash){
        if(discover[x.second] == -1) dfs(x.second);
    }

    vector<long long> sum(key+1, 1);
    for(int i=scc_cnt-1; i>=0; i--){
        for(auto cur: res[i]){
            for(auto next: adj[cur]){
                if(scc[cur] != scc[next]){
                    sum[next] += sum[cur];
                }
            }
        }
    }
    cout << sum[hash[tg]] << '\n';

    return 0;
}