#include <iostream>
#include <vector>
#include <queue>
#define INF 1e14
#define ll long long
using namespace std;

typedef pair<ll, ll> pll;
ll N, M, S, E;
vector<pll> adj[55];
vector<ll> rev[55], reached[55], v[55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S >> E >> M;
    for(int i=0; i<M; i++){
        ll a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        rev[b].push_back(a);
    }
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }

    return 0;
}