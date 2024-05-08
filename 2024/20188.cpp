#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> adj[300010];
int N, child[300010];
ll ans;

int makeTree(int parent, int cur)
{
    ll tmp;
    for(auto next: adj[cur]){
        if(next == parent) continue;
        tmp = makeTree(cur, next);
        ans += tmp * (tmp - 1) / 2;
        ans += tmp * (N - tmp);
        child[cur] += tmp;
    }
    return ++child[cur];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    makeTree(0, 1);

    cout << ans << '\n';

    return 0;
}