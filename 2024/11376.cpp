#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[2010];
int l[2010], r[1010];
bool visit[2010];

bool dfs(int a)
{
    if(visit[a]) return false;
    visit[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visit[r[b]] && dfs(r[b])){
            l[a] = b;
            r[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++){
        int k; cin >> k;
        for(int j=0; j<k; j++){
            int v; cin >> v;
            adj[i].push_back(v - 1);
            adj[i+N].push_back(v - 1);
        }
    }

    int ans = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i=0; i<N*2; i++){
        if(l[i] == -1){
            memset(visit, false, sizeof(visit));
            if(dfs(i)) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}