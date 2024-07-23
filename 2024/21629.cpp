#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

vector<pii> adj(200010);
bool visited[100010], check[100010];
int res, cnt[100010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[i] = {u, v};
        if(u == 1) check[v] = true;
        else if(v == 1) check[u] = true;
    }

    for(int i=0; i<M; i++){
        if(check[adj[i].first]) cnt[adj[i].second]++;
        if(check[adj[i].second]) cnt[adj[i].first]++;
    }
    for(int i=2; i<=N; i++){
        res += cnt[i] * (cnt[i] - 1);
    }
    cout << res << '\n';

    return 0;


    return 0;
}