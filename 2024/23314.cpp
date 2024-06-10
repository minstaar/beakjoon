#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
vector<pii> adj[100010];
int dfn[100010], low[100010], id;
int edge_color[200010], color_cnt;
bool visited[100010];

int dfs(int cur)
{
    dfn[cur] = low[cur] = ++id;
    int& ret = low[cur];
    for(auto [next, idx]: adj[cur]){
        if(dfn[next] == 0){
            int t = dfs(next);
            ret = min(ret, t);
        }
        else ret = min(ret, dfn[next]);
    }
    return ret;
}

void color(int cur, int p_idx, int p)
{
    if(p) edge_color[p_idx] = p;
    visited[cur] = true;
    for(auto [next, idx]: adj[cur]){
        if(visited[next]){
            if(edge_color[idx] == 0){
                edge_color[idx] = p;
            }
        }
        else if(low[next] >= dfn[cur]){
            edge_color[idx] = ++color_cnt;
            color(next, idx, color_cnt);
        }
        else color(next, idx, p);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    vector<tuple<int, int, int>> edges(M);
    for(auto& [u, v, c]: edges){
        cin >> u >> v >> c;
        if(u > v) swap(u, v);
    }
    sort(edges.begin(), edges.end());
    for(int i=0; i<M; i++){
        auto [u, v, c] = edges[i];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    dfs(1), color(1, 0, 0);
    vector<multiset<int>> S(M+1);
    vector<ll> sum(M+1);
    for(int i=0; i<M; i++){
        S[edge_color[i]].insert(get<2>(edges[i]));
        sum[edge_color[i]] += get<2>(edges[i]);
    }

    ll res = 0;
    for(int i=1; i<=M; i++){
        if(S[i].size() >= 3){
            int t = *prev(S[i].end());
            res += (t < 0 ? sum[i] : sum[i] - t);
        }
        else if(S[i].size() == 1) res += sum[i];
    }
    cout << res << '\n';
    while(Q--){
        int u, v, c; cin >> u >> v >> c;
        if(u > v) swap(u, v);
        int idx = lower_bound(edges.begin(), edges.end(), make_tuple(u, v, -1e9)) - edges.begin();
        int color = edge_color[idx];
        if(S[color].size() >= 3){
            int t = *prev(S[color].end());
            res -= (t < 0 ? sum[color] : sum[color] - t);
        }
        else res -= sum[color];
        S[color].erase(S[color].find(get<2>(edges[idx])));
        sum[color] -= get<2>(edges[idx]);
        
        edges[idx] = {u, v, c};
        S[color].insert(c);
        sum[color] += c;
        if(S[color].size() >= 3){
            int t = *prev(S[color].end());
            res += (t < 0 ? sum[color] : sum[color] - t);
        }
        else res += sum[color];

        cout << res << '\n';
    }

    return 0;
}