#include <bits/stdc++.h>
using namespace std;

template<class flow_t> struct Dinic{
    struct Edge{
        int next, dual;
        flow_t spare;
    };
    const flow_t INF = numeric_limits<flow_t>::max() / 2;
    int n;
    vector<int> level, work;
    vector<vector<Edge>> adj;

    Dinic(int _n): n(_n), adj(_n) {}
    
    void addEdge(int u, int v, flow_t cap, flow_t recap = 0){
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, recap});
    }

    bool bfs(int S, int T){
        level = vector<int>(n+1, -1);
        level[S] = 0;
        queue<int> que;
        que.push(S);
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto [next, dual, spare]: adj[cur]){
                if(level[next] == -1 && spare > 0){
                    level[next] = level[cur] + 1;
                    que.push(next);
                }
            }
        }
        return level[T] != -1;
    }

    flow_t dfs(int cur, int T, flow_t flow){
        if(cur == T) return flow;
        for(int &i=work[cur]; i<adj[cur].size(); i++){
            auto &[next, dual, spare] = adj[cur][i];
            if(level[next] == level[cur] + 1 && spare > 0){
                flow_t df = dfs(next, T, min(spare, flow));
                if(df > 0){
                    spare -= df;
                    adj[next][dual].spare += df;
                    return df;
                }
            }
        }
        return 0;
    }

    flow_t get_maxflow(int S, int T){
        flow_t total = 0;
        while(bfs(S, T)){
            work = vector<int>(n+1, 0);
            while(1){
                flow_t flow = dfs(S, T, INF);
                if(flow == 0) break;
                total += flow;
            }
        }
        return total;
    }

    flow_t getflow(int v, int e){
        return adj[v][e].spare;
    }

    bool cutSide(int v){
        return level[v] != -1;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int t=1; t<=T; t++){
        int N; cin >> N;
        cin.ignore();
        vector<string> sentence[N];
        map<string, int> idx;
        int pv = 1;
        for(int i=0; i<N; i++){
            string str, input; getline(cin, input);
            stringstream stream(input);
            while(stream >> str){
                if(idx.find(str) == idx.end()) idx[str] = pv++;
                sentence[i].push_back(str);
            }
        }
        
        Dinic<int> dinic(idx.size() * 2 + 3);
        int S = 0, T = 1;
        for(auto s: sentence[0]){
            dinic.addEdge(S, idx[s] * 2, 1e9);
        }
        for(auto s: sentence[1]){
            dinic.addEdge(idx[s] * 2 + 1, T, 1e9);
        }
        for(int i=2; i<N; i++){
            for(int j=0; j<sentence[i].size()-1; j++){
                for(int k=j+1; k<sentence[i].size(); k++){
                    dinic.addEdge(idx[sentence[i][j]] * 2 + 1, idx[sentence[i][k]] * 2, 1e9);
                    dinic.addEdge(idx[sentence[i][k]] * 2 + 1, idx[sentence[i][j]] * 2, 1e9);
                }
            }
        }
        for(auto x: idx){
            dinic.addEdge(x.second * 2, x.second * 2 + 1, 1);
        }

        cout << "Case #" << t << ": " << dinic.get_maxflow(S, T) << '\n';
    }

    return 0;
}