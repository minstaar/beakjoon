#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> adj[1010];
ll res;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=N; i++){
        vector<int> cnt(N+1);
        for(auto next: adj[i]){
            for(auto next2: adj[next]){
                cnt[next2]++;
            }
        }
        for(int j=1; j<=N; j++){
            if(i >= j) continue;
            res += cnt[j] * (cnt[j] - 1) / 2;
        }
    }

    cout << res / 2 << '\n';

    return 0;
}