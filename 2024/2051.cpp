#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[1010];
int N, M;
int l[1010], r[1010];
bool visit[1010], track[2010];

bool dfs(int a)
{
    if(visit[a]) return false;
    visit[a] = true;
    for(auto b: adj[a]){
        if(r[b] == -1 || !visit[r[b]] && dfs(r[b])){
            l[a] = b, r[b] = a;
            return true;
        }
    }
    return false;    
}

void dfs_track(int cur)
{
    if(track[cur]) return;
    track[cur] = true;
    for(auto next: adj[cur]){
        track[next+N] = true;
        dfs_track(r[next]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        int k; cin >> k;
        for(int j=0; j<k; j++){
            int v; cin >> v;
            adj[i].push_back(v-1);
        }
    }

    int match = 0;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i=0; i<N; i++){
        if(l[i] == -1){
            memset(visit, false, sizeof(visit));
            if(dfs(i)) match++;
        }
    }

    vector<int> lv, rv;
    memset(track, false, sizeof(track));
    for(int i=0; i<N; i++){
        if(l[i] == -1) dfs_track(i);
    }
    for(int i=0; i<N; i++){
        if(!track[i]) lv.push_back(i);
    }
    for(int i=0; i<M; i++){
        if(track[i+N]) rv.push_back(i);
    }
    
    cout << match << '\n';
    cout << lv.size() << ' ';
    for(auto x: lv) cout << x + 1<< ' ';
    cout << '\n';
    cout << rv.size() << ' ';
    for(auto x: rv) cout << x + 1<< ' ';

    return 0;
}