#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> adj[1010];
int l[1010], r[1010];
bool visited[1010];

bool dfs(int a)
{
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visited[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int t; cin >> t;
        for(int j=0; j<t; j++){
            int a; cin >> a;
            adj[i].push_back(a - 1);
        }
    }

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i=0; i<N; i++){
        if(l[i] == -1){
            memset(visited, false, sizeof(visited));
            dfs(i);
        }
    }

    vector<int> matched[2010], inDegree(2010);
    for(int i=0; i<N; i++){
        for(auto next: adj[i]){
            if(next == l[i]){
                matched[i].push_back(next + N);
                inDegree[next+N]++;
            }
            else{
                matched[next+N].push_back(i);
                inDegree[i]++;
            }
        }
    }
    queue<int> que;
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(inDegree[i] == 0){
            que.push(i);
            cnt++;
        }
    }
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(auto next: matched[cur]){
            if(--inDegree[next] == 0){
                que.push(next);
                cnt++;
            }
        }
    }
    if(cnt != 2 * N) cout << -1 << '\n';
    else{
        cout << 1 << '\n';
        for(int i=0; i<N; i++) cout << l[i] + 1 << ' ';
        cout << '\n';
    }

    return 0;
}