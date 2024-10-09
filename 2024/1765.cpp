#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int N): parent(N, -1){};
    int Find(int x){
        return parent[x] < 0 ? x : parent[x] = Find(parent[x]);
    }
    bool Union(int x, int y){
        x = Find(x), y = Find(y);
        if(x == y) return false;
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    UnionFind UF(N+1);
    vector<int> adj[1010];
    for(int i=0; i<M; i++){

        char op; int x, y; cin >> op >> x >> y;
        if(op == 'F'){
            UF.Union(x, y);
        }
        else{
            for(auto next: adj[x]){
                UF.Union(next, y);
            }
            for(auto next: adj[y]){
                UF.Union(next, x);
            }
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(UF.parent[i] < 0) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}