#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int N, arr[2][510];
int S, T;
vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX], res[510][510];

void addEdge(int u, int v, int cap, int recap)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] = cap;
    c[v][u] = recap;
}

int get_maxflow()
{
    int total = 0;
    while(1){
        vector<int> prev(MAX, -1);
        queue<int> que;
        que.push(S);
        while(!que.empty() && prev[T] == -1){
            int cur = que.front();
            que.pop();
            for(auto next: adj[cur]){
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1){
                    prev[next] = cur;
                    que.push(next);
                    if(next == T) break;
                }
            }
        }
        if(prev[T] == -1) break;
        int flow = 1e9;
        for(int i=T; i!=S; i=prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for(int i=T; i!=S; i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }
    return total;
}

bool check()
{
    for(int i=1; i<=N; i++){
        int sumR = 0, sumC = 0;
        for(int j=1; j<=N; j++){
            sumR += res[i][j];
            sumC += res[j][i];
        }
        if(sumR != arr[0][i] || sumC != arr[1][i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    S = 0, T = 2 * N + 1;
    for(int i=1; i<=N; i++){
        addEdge(S, i, arr[0][i], 0);
        addEdge(i + N, T, arr[1][i], 0);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            addEdge(i, j + N, 1, 0);
        }
    }
    
    get_maxflow();

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            res[i][j] = (f[i][j+N] ? 1 : 0);
        }
    }

    if(check()){
        cout << 1 << '\n';
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cout << res[i][j];
            }
            cout << '\n';
        }
    }
    else cout << "-1\n";

    return 0;
}