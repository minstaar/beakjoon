#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int sz[100010], color[100010];
bool visited[100010];
vector<int> adj[100010];
map<int, int> mp;

int getSize(int prev, int cur)
{
    sz[cur] = 1;
    for(auto next: adj[cur]){
        if(next != prev && !visited[next]){
            sz[cur] += getSize(cur, next);
        }
    }
    return sz[cur];
}

int getCent(int prev, int cur, int cnt)
{
    for(auto next: adj[cur]){
        if(next != prev && !visited[next] && sz[next] * 2 > cnt){
            return getCent(cur, next, cnt);
        }
    }
    return cur;
}

void update(int prev, int cur, int depth)
{
    auto it = mp.find(color[cur]);
    if(it != mp.end()){
        it->second = min(it->second, depth);
    }
    else mp[color[cur]] = depth;
    for(auto next: adj[cur]){
        if(next != prev && !visited[next]){
            update(cur, next, depth + 1);
        }
    }
}

int solve(int prev, int cur, int depth)
{
    int ret = INF;
    auto it = mp.find(color[cur]);
    if(it != mp.end()){
        ret = min(ret, it->second + depth);
    }
    for(auto next: adj[cur]){
        if(next != prev && !visited[next]){
            ret = min(ret, solve(cur, next, depth + 1));
        }
    }
    return ret;
}

int dnc(int cur)
{
    int cent = getCent(-1, cur, getSize(-1, cur));
    visited[cent] = true;
    int ret = INF;
    mp.clear();
    mp[color[cent]] = 0;
    for(auto next: adj[cent]){
        if(!visited[next]){
            ret = min(ret, solve(cent, next, 1));
            update(cent, next, 1);
        }
    }
    for(auto next: adj[cent]){
        if(!visited[next]){
            ret = min(ret, dnc(next));
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> color[i];
    for(int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dnc(1) << '\n';

    return 0;
}